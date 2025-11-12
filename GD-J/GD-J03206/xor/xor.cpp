#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],s,t;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=(a[i]==0),t+=a[i];
	if(k==0)cout<<n/2;
	else cout<<t;
	return 0;
}

