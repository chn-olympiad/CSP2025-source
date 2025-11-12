#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll op=1e6+10,oq=1e4+10;
ll m,n,k,u[op],v[op],w[op],a[oq][20],c[20],b[oq],ans,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(b,0x3f,sizeof(b));
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		cnt+=w[i];
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[j][i];
			b[j]=min(b[j],a[j][i]);
		}
	}
	for(ll i=1;i<=n;i++){
		ans+=b[i];
	}
	cout<<min(ans,cnt);
	
	return 0;
}
