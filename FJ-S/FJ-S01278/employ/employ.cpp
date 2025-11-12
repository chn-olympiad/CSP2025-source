#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n+5];
	long long a;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	cout<<n<<m;
	long long ansup=1,ansend=1;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<' ';
		ansup*=i;
		ansup%=998244353;
	}
	for(int i=1;i<=m;i++)
	{
		ansup*=i;
		ansend%=998244353;
	}
	long long ans=ansup;
	cout<<ans%998244353;
}

