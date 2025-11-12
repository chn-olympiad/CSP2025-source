#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e6+5,N=1e4+5;
int fa[N],b[15][N],B[15];
bool vis[N];
struct nn{
	int x,y,z;
}a[M],bb[M];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void un(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)fa[y]=x;
}
bool cmp(nn x,nn y){
	return x.z<y.z;
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x;
}
vector<int>nbr[N];
int n;
int get(int m,int k){
	for(int i=1;i<=m;i++)bb[i]=a[i];
	for(int i=1;i<=n+10;i++)fa[i]=i;
	sort(bb+1,bb+1+m,cmp);
	int c=0,ans=0;
	for(int i=1;i<=m;i++){
		if(find(bb[i].x)==find(bb[i].y))continue;
		un(bb[i].x,bb[i].y);
		ans+=bb[i].z;
		c++;
		if(c==n+k-1){
			break;
		}
	}
	return ans;
}
int m,k,ans=1e18,S;
void dfs(int x,int sum,int kk){
	if(sum+S>=ans)return;
	if(x-1==k){
		int mm=m;
		for(int i=1;i<=k;i++){
			if(!vis[i])continue;
			for(int j=1;j<=n;j++){
				a[++mm]={i+n,j,b[i][j]};
			}
		}
//		for(int i=1;i<=mm;i++){
//			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n";
//		}
//		cout<<"\n";
		ans=min(ans,get(mm,kk)+sum);
		return;
	}
	dfs(x+1,sum,kk);
	vis[x]=1;
	dfs(x+1,sum+B[x],kk+1);
	vis[x]=0;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		a[i].x=read();
		a[i].y=read();
		a[i].z=read();
	}
	S=get(m,k);
	ans=S;
	if(k<=5){
		for(int i=1;i<=k;i++){
			B[i]=read();
			for(int j=1;j<=n;j++){
				b[i][j]=read();
			}
		}
//		ans=1e18;
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	int mm=m;
	for(int i=1;i<=k;i++){
		int h=read();
		for(int j=1;j<=n;j++){
			int x=read();
			a[++mm]={i+n,j,x};
		}
	}
	cout<<get(mm,k);
	return 0;
}

