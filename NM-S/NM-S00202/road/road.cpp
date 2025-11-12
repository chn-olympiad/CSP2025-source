#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10000+4;
ll n,m,k;
ll v[N];
ll u[N];
ll w[N];
ll c[N];
ll a[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;++i){
    	scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
    }
    for(int i=1;i<=k;++i){
    	scanf("%lld",&c[i]);
    	for(int j=1;j<=n;++j){
    		scanf("%lld",&a[j]);
		}
	}
    return 0;
}
