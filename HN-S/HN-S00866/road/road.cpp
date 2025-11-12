#include <bits/stdc++.h>

#define fst first
#define sec second
#define pb push_back
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using p_q = priority_queue<pair<ll,pair<int,int> > >;

const int N = 1e4+50,M=2e6+50;

pair<ll,pair<int,int> > ed[M],ed1[M];
ll ct[15][N];
int fa[N];
int isbx[N];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ed[i].sec.fst>>ed[i].sec.sec>>ed[i].fst;
	}
	for(int i=1;i<=k;i++){
		cin>>ct[i][0];ll mn=1e18; 
		for(int j=1;j<=n;j++){
			cin>>ct[i][j];mn=min(mn,ct[i][j]);
		}
		if(mn+ct[i][0]<=0){
			isbx[i]=1;
		}
	}
	ll ans=1e18,rs=0;
	for(int s=0;s<(1<<k);s++){
		int cnt=0;
		ll tans=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		int rn=n,isok=1;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				if(isbx[i]){
					isok=0;break;
				}
				for(int j=1;j<=n;j++){
					ed1[++cnt].fst=ct[i][j];ed1[cnt].sec.fst=n+i,ed1[cnt].sec.sec=j;
				}
				rn++,tans+=ct[i][0];
			}
			if(isbx[i]){
				for(int j=1;j<=n;j++){
					ed1[++cnt].fst=ct[i][j];ed1[cnt].sec.fst=n+i,ed1[cnt].sec.sec=j;
				}
				rn++,tans+=ct[i][0];
			}
		}
		if(!isok) continue;
		for(int i=1;i<=m;i++){
			ed1[++cnt]=ed[i];
		}
		sort(ed1+1,ed1+cnt+1);
		for(int i=1;i<=cnt;i++){
			int X=find(ed1[i].sec.fst),Y=find(ed1[i].sec.sec);
			if(fa[X]==fa[Y]) continue;
			fa[X]=Y,rn--,tans+=ed1[i].fst;
			if(rn==1) break;
		}
		if(rn==1) ans=min(ans,tans);
		if((rs+1ll)*m>3e7) break;
		rs++;
	}
	cout<<ans<<endl;

	return 0;
}

