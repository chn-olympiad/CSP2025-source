#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long n,m,k,ans;
long long u[maxn],v[maxn],w[maxn],a[maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		long long c;
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	cout<<ans;
	return 0;
}
