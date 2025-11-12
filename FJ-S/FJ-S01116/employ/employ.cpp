#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n,m,a;
long long ans=1;
string x1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>x1;
	for(int i=1;i<=n;i++) cin>>a;
	for(int i=m;i<=n;i++)
	  ans=(ans*i)%Mod;
	cout<<ans;
	return 0;
}
