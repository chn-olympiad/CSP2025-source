#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,ans;
char a[505];
long long b[505],sum=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(long long i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(long long i=0;i<n;i++)
	{
		if(a[i]=='1')
		{
			ans++;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		sum*=i;
	}
	if(m==n)
	{
		if(ans!=n)
		{
			cout<<"0";
			return 0;
		}
	}
	if(m==1)
	{
		if(ans==0)
		cout<<"0";
		else
		cout<<sum;
		return 0;
	}
	if(ans==n)
	{
		cout<<sum;
		return 0;
	}
	return 0;
}
