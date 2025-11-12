#include<bits/stdc++.h>//20
#define int long long
using namespace std;
const int N=510,mod=998244353;
int n,m,sum,ans=1,c[N];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		ans=ans*n%mod;
		n--;
	}
	cout<<ans%mod;
	return 0;
}
