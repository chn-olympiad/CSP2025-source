#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[501],a[501];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=1;
	for(int i=1;i<=n;i++) ans*=i,ans%=998244353;
	cout<<ans; 
}
