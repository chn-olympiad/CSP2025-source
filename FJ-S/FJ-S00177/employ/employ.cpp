#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k;
ll u[10005],v[10005],w[1000005],c[100005]; 
ll cnt[10005];
ll ans;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if( cnt[u[i]] == 0 || cnt[v[i]] == 0){
			ans+=w[i];
			cnt[u[i]]++;
			cnt[v[i]]++;
		}
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
	}
	
	cout<<ans<<endl;
	
	return 0;
}
