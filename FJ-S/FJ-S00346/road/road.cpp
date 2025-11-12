#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll N=10005;
const ll M=1000005;
ll n,m,k,ans;
ll u[M],v[M],w[M],c[15],a[15][N];
ll hea[N],nex[M],nod[M],co[M],ndx,r[N],r2[N];
bool have[N],wg[N];
ll hdx;
ll need[N],q[N],qdx,ans2;
bool sorter(ll a,ll b) {
	return (u[a]>u[b]);
}
void add(ll a,ll b,ll cost) {
	nex[ndx]=hea[a];
	hea[a]=ndx;
	nod[ndx]=b;
	co[ndx++]=cost;
}
int main() {
	freopen("road1.in","r",stdin),freopen("road1.ans","w",stdout);
	memset(q,-1,sizeof(q));
	memset(nex,-1,sizeof(nex));
	memset(hea,-1,sizeof(hea));
	cin>>n>>m>>k;
	for(ll i=0; i<m; i++) {
		cin>>u[i]>>v[i]>>w[i];
		u[i]-=1;
		v[i]-=1;
	}
	for(ll i=0; i<m; i++) {
		add(u[i],v[i],w[i]);
		add(v[i],u[i],w[i]);
	}
	for(ll i=0; i<k; i++) {
		cin>>c[i];
		for(ll j=0; j<n; j++) {
			cin>>a[i][j];
		}
	}
	have[0]=true;
	q[0]=0;
	for(ll i=0; q[i]!=-1; i++) {
		for(ll point=hea[q[i]]; point!=-1; point=nex[point]) {
			if(!have[nod[point]]) {
				need[nod[point]]=q[i];
				r[nod[point]]=co[point];
				ans+=co[point];
				have[nod[point]]=true;
				q[++qdx]=nod[point];
			} else {
				if(co[point]<r[nod[point]]) {
					ans-=r[nod[point]];
					ans+=co[point];
					r[nod[point]]=co[point];
					need[nod[point]]=q[i];
				}
			}
		}
	}
	for(ll i=0; i<k; i++) {
		memset(wg,0,sizeof(wg));
		for(int j=0; j<n; j++) {
			r2[j]=r[j];
		}
		ans2=ans+c[i];
		for(ll g=0; g<n; g++) {
			for(ll h=0; h<n; h++) {
				if(g==h) {
					continue;
				}
				ll y=a[i][g]+a[i][h];
				if(wg[g]) {
					y-=a[i][g];
				}
				if(wg[h]) {
					y-=a[i][h];
				}
				if(y<r[g]) {
					ans2-=r[g];
					ans2+=y;
					wg[g]=true;
					wg[h]=true;
					r[g]=y;
				}
			}
		}
		ans=min(ans,ans2);
	}
	cout<<ans;
}
