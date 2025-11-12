#include<bits/stdc++.h>
#define int long long
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,ans;
int f[N];
struct edge{
	int u,v,c;
}e1[M],e2[N],e3[11][N],e4[N*11];
bool cmp(edge aa,edge bb){
	return aa.c<bb.c;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int tp,cost[N];
signed main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	forr(i,1,n)f[i]=i;
	forr(i,1,m){
		cin>>e1[i].u>>e1[i].v>>e1[i].c;
	}
	sort(e1+1,e1+1+m,cmp);
	forr(i,1,m){
		int fx=find(e1[i].u),fy=find(e1[i].v);
		if(fx!=fy){
			f[fx]=fy;
			ans+=e1[i].c;
			e2[++tp]=e1[i];
		}
	}
	forr(i,1,k){
		cin>>cost[i];
		forr(j,1,n){
			int tt;cin>>tt;
			e3[i][j]={n+i,j,tt};
		}
	}
	forr(i,0,(1<<k)-1){
		tp=0;int ts=0;
		forr(j,1,n-1)e4[++tp]=e2[j];
		forr(l,1,k){
			if((i&(1<<(l-1)))){
				ts+=cost[l];
				forr(tt,1,n){	
					e4[++tp]=e3[l][tt];
				}
			}
		}
		forr(j,1,n+k){
			f[j]=j;
		}
		sort(e4+1,e4+1+tp,cmp);
		forr(j,1,tp){
			int fx=find(e4[j].u),fy=find(e4[j].v);
			if(fx!=fy){
				f[fx]=fy;
				ts+=e4[j].c;
			}
		}
		ans=min(ans,ts);
	}
	cout<<ans;
	return 0;
}
