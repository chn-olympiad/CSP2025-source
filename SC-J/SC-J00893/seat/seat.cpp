#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010];
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++) if(a[i]==t){
		int u=(i-1)/n+1,v=(i-1)%n+1;
		if(u&1) cout<<u<<" "<<v;
		else cout<<u<<" "<<n-v+1;
	}
	return 0;
}