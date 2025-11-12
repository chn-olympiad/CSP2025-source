#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int N=510;
int a[N];
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long ans=1;
	for(int i=n;i>=1;i--)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
