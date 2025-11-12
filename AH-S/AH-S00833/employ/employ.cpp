#include<iostream>
using namespace std;
const int N=1e6+5;
int n,m,c[N];
long long ans,mod=998244353;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	ans=n;
	for(int i=n-1;i>=1;i--)
		ans=ans*i%mod;
	cout<<ans;
	return 0;
}
