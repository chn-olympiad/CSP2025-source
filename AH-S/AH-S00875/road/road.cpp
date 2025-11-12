#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int n,m,k,ans=1000000000;
int c[11][N],v[11];
struct edge{
	int x;
	int y;
	int z;
}e[2000010],f[2000010];
int fa[N];
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
bool cmp(edge x,edge y){
	return x.z<y.z;
}
int se[11];
void dfs(int x){
	if(x>k){
		int ans1=0,tot=m,n1=n;
		for(int i=1;i<=m;i++)
			f[i]=e[i];
		for(int i=1;i<=k;i++){
			// cout<<se[i]<<" ";
			if(se[i]){
				ans1+=v[i];
				n1++;
				for(int j=1;j<=n;j++)
					f[++tot]={n1,j,c[i][j]};
			}
			
		}
		sort(f+1,f+1+tot,cmp);
		iota(fa,fa+n1+1,0);
		// cout<<"*"<<tot;
		// for(int i=1;i<=tot;i++)
		// 	cout<<f[i].x<<" "<<f[i].y<<" "<<f[i].z<<endl;
		// cout<<endl;
		for(int i=1;i<=tot;i++){
			int x=f[i].x,y=f[i].y,z=f[i].z;
			if(get(x)==get(y))continue;
			ans1+=z;
			fa[get(x)]=get(y);
		}
		// cout<<ans1<<endl;
		ans=min(ans,ans1);

		

		// cout<<endl;
		return;
	}
	se[x]=0;
	dfs(x+1);
	se[x]=1;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>e[i].x>>e[i].y>>e[i].z;
		}
		for(int i=1;i<=k;i++){
			cin>>v[i];
			for(int j=1;j<=n;j++)
				cin>>c[i][j];
		}
	if(k==0){
		ans=0;
		sort(e+1,e+1+m,cmp);
		iota(fa,fa+n+1,0);
		for(int i=1;i<=m;i++){
			int x=e[i].x,y=e[i].y,z=e[i].z;
			if(get(x)==get(y))continue;
			ans+=z;
			fa[get(x)]=get(y);
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}