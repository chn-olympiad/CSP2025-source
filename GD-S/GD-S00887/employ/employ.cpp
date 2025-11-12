#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int n1=n;
	long long ans=1;
	for(int i=0;i<n;i++)
	{
		int q;
		cin>>q;
		if(q==0)
		{
			n1--;
		}
	}
	for(int i=1;i<=n1;i++)
	{
		ans*=i;
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}
