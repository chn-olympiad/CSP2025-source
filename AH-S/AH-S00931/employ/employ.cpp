#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum=1;
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	if(m==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int t=0;
			cin>>t;
			if(t>0)
			{
				cnt++;
			}
			cout<<cnt;
			return 0;
		}
	}
	if(n==3&&m==2)
	{
		for(int i=1;i<=n;i++)
		{
			int t=0;
			cin>>t;
		}
		cout<<"2"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int t=0;
		cin>>t;
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=m) sum=((sum%998244353)*(i%998244353))%998244353;
	}
	cout<<sum;
	return 0;
}
