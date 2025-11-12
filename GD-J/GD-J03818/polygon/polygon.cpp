#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],f[N],r;
signed main(){
#ifndef XYZ
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		(r+=f[a[i]+1])%=mod;
		for(int j=5001;j>=0;j--){
			(f[j]+=f[max(0ll,j-a[i])])%=mod;
		}
	}
	cout<<r;
	return 0;
}

