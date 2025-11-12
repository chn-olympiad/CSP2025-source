#include<bits/stdc++.h>
using namespace std;
struct my{
	int u,v,w;
}a[2000005];
my t[2000005];
int b[15][100005];
bool f[15];
int c[15];
int fa[10005];
int n,m,k;
int find(int x){
	if(x==fa[x]){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
long long ans;
int p=2147483647;
int merge(int x,int y,int s){
	p=min(p,s);
	int tx=x;
	int ty=y;
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y; 
		ans+=s;
	}
}
bool cmp(my x,my y){
	return x.w<y.w;
}
long long zsum=0x3f3f3f3f3f3f3f3f;
long long ansmi(int ew){
	p=2147483647;
	ans=0;
	int cnt=m;
	for(int i=1;i<=m;i++){
		a[i]=t[i];
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		if(f[i]==1){
			for(int j=1;j<=n;j++){
				a[++cnt].u=i;
				a[cnt].v=j;
				a[cnt].w=b[i][j];
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		merge(a[i].u,a[i].v,a[i].w);
		if(ans+ew>zsum){
			return 0x3f3f3f3f3f3f3f3f;
		}
	}
	return ans+ew;
}
void dfs(int id,int sum){
	if(id==k+1){
		zsum=min(zsum,ansmi(sum));
		return ;
	}
	f[id]=1;
	dfs(id+1,sum+c[id]);
	f[id]=0;
	dfs(id+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	
	for(int i=1;i<=k;i++){
	    cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	dfs(1,0);
	cout<<zsum;
	return 0;
}