#include<bits/stdc++.h>
using namespace std;
const int N=10000+5,M=1000000+5;
int n,m,k;
int cnt=0;
int fa[N+10];
long long c[N];
int idd[1005][1005];
struct sss{
	int u,v;
	long long w;
}e[N*10+M];
vector<sss>p;
long long ans=0;
bool cmp(sss a,sss b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void me(int x,int y,long long w){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		p.push_back({x,y,w});
		ans+=w;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
		if(n<=1000){
			idd[e[i].v][e[i].u]=i;
			idd[e[i].u][e[i].v]=i;
		}
	}
	cnt=m;
	/*for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int i=1;i<=n;i++){
			int w;
			cin>>w;
			e[++cnt].u=i+n;
			e[cnt].v=i;
			e[cnt].w=w;
		}
	}*/
	//cout<<k<<endl;
	for(int i=1;i<=k;i++){
		int w;
		scanf("%d",&w);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[j]);
		}
		if(n<=1000){
			for(int j=1;j<=n;j++){
				for(int l=1;l<j;l++){
					if(idd[j][l]==0){
						idd[j][l]=++cnt;
						idd[l][j]=cnt;
						e[idd[j][l]]=(sss){j,l,c[j]+c[l]};
						continue;
					}
					if(c[j]+c[l]<e[idd[j][l]].w){
						e[idd[j][l]].w=c[j]+c[l];
					}
				}
			}
		}
	}
	//cout<<cnt<<endl;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		me(e[i].u,e[i].v,e[i].w);
	}
	/*for(int i=1;i<=k;i++){
		if(cs[i]==1){
			for(int i=0;i<p.size();i++){
				int u=p[i].u;
				if(u==i+n){
					ans-=p[i].w;
					break;
				}
			}
		}
	}*/
	printf("%lld",ans);
	return 0;
}
