#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
bool q=1;
struct f{
	int u,v,w;
}e[2000005];
int fa[20005];
bool cmp(f a,f b){
	return a.w<b.w;
}
int b[15][10005];
int vs[15];
int find(int x){
	if(fa[x]==x){
		return fa[x];
	}else{
		return fa[x]=find(fa[x]);
	}
}
int minn=0x7fffffffffffffff;
int vsss[15][10005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>b[i][j];
		}
		if(b[i][0]!=0){
			q=0;
		} 
	}
	if(q==1 && m>100000){
		sort(1+e,1+e+m,cmp);
		int ans=0;
		for(int j=1;j<=n;j++){
			fa[j]=j;
		}
		for(int j=1;j<=m;j++){
			int u=e[j].u,v=e[j].v,w=e[j].w;
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				fa[fv]=fu;
				int minn=w,ki;
				for(int i=1;i<=k;i++){
					int xw=b[i][u];
					int yw=b[i][v];
					int sum=0;
					if(vsss[i][u]==1){
						sum=yw;
					}
					if(vsss[i][v]==1){
						sum=xw;
					}
					if(vsss[i][v]==0 && vsss[i][u]==0){
						sum=yw+xw;
					}
					if(minn>=sum){
						minn=sum;
						ki=i;
					}
				}
				ans+=minn;
				if(ki){
					vsss[ki][u]=1;
					vsss[ki][v]=1;
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			if(j!=0){
				m++;
				e[m]={i+n,j,b[i][j]};
			}
		}
	}
	sort(1+e,1+e+m,cmp);
	int www;
	if(k==0){
		www=0;
	}else{
		www=(1<<(k-1));
	}
	for(int i=0;i<=www;i++){
		int ans=0,y=i;
		for(int j=1;j<=k;j++){
			vs[j]=0;
			if(y&1==1){
				vs[j]=1;
				ans+=b[j][0];
			}
			y>>=1;
		}
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int j=1;j<=m;j++){
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(u>n){
				int x=u-n;
				if(vs[x]==0){
					continue;
				}
			}
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				fa[fv]=fu;
				ans+=w;
			}
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0;
}

