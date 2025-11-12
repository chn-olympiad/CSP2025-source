#include<bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int u[1000005], v[1000005], w[1000005];
int c[1000005], a[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++) cin>>a[j];
	}
	sort(w+1,w+1+n);
	sort(c+1,c+1+k);
	for(int i=1;i<=k;i++){
		ans+=w[i];
	}
	cout<<ans+c[1];
    return 0;
}

