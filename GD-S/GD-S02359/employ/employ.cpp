#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int c[505];
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		ans*=i;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
 } 
