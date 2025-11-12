#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
#define int long long
const int N=2e5+7;
const int M=1e6+7;
int T,n,m,k;

int x[13][N];


struct node{
	int u,v,c;
}edge[M],e[2*M];
bool cmp(node a,node b){
	return a.c<b.c;
}
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int Kru(int cc,int nx){
	sort(e+1,e+1+cc,cmp);
	rep(i,1,n+k) fa[i]=i;
	int ans=0,cnt=0;
	rep(i,1,cc){
		int u=e[i].u,v=e[i].v,c=e[i].c;
		int f1=find(u),f2=find(v);
		if(f1==f2) continue;
		fa[f1]=f2;
		ans+=c;
		if(++cnt==nx-1) break;
	}
	return ans;
}
int kkKru(){
	sort(edge+1,edge+1+m,cmp);
	rep(i,1,n) fa[i]=i;
	int ans=0,cnt=0;
	rep(i,1,m){
		int u=edge[i].u,v=edge[i].v,c=edge[i].c;
		int f1=find(u),f2=find(v);
		if(f1==f2) continue;
		e[++cnt]=edge[i];
		fa[f1]=f2;
		ans+=c;
		if(cnt==n-1) break;
	}
	return ans;
}
bool tepan(){
	bool f=1;
	rep(i,1,k){
		if(x[i][0]) return 0;
		bool s=0;
		rep(j,1,n){
			if(x[i][j]==0) s=1;
		}
		if(!s) return 0;
	}
	rep(i,1,k){
		rep(j,1,n){
			edge[++m]={n+i,j,x[i][j]};
		}
	}
	sort(edge+1,edge+1+m,cmp);
	rep(i,1,n+k) fa[i]=i;
	int ans=0,cnt=0;
	rep(i,1,m){
		int u=edge[i].u,v=edge[i].v,c=edge[i].c;
		int f1=find(u),f2=find(v);
		if(f1==f2) continue;
		e[++cnt]=edge[i];
		fa[f1]=f2;
		ans+=c;
		if(cnt==n+k-1) break;
	}
	cout<<ans<<'\n';
	return 1;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m){
		cin>>edge[i].u>>edge[i].v>>edge[i].c;
	}
	rep(i,1,k){
		rep(j,0,n){
			cin>>x[i][j];
		}
	}
	if(tepan())
		return 0;
	ll A=kkKru();
	m=n-1;
	rep(i,0,(1<<k)-1){
		ll t=m,ans=0,po=0;
		rep(j,1,k){
			if(i>>(j-1)&1){
				po++;
				ans+=x[j][0];
				rep(s,1,n)
					e[++t]=node{n+j,s,x[j][s]};
			}
		}
		ans+=Kru(t,n+po);
		A=min(A,ans);
	}
	cout<<A<<'\n';
	return 0;
}