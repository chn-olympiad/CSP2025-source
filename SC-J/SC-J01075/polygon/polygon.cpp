#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n;
int a[5005];
int cnt,maxn;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);         
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<3) cout<<"0";
	else {
		maxn*=2;
		if(cnt<=maxn) cout<<"0";
		else cout<<"1";
	}
	return 0; 
 } 