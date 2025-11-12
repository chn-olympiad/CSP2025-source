#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n;
int sum=1;
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
	sum=(sum*n)%mod;
cout<<sum;
return 0;
}
