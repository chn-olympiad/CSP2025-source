#include<bits/stdc++.h>
using namespace std;
long long a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,num=0;
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n-2;l++)
	{
		for(int r=l+2;r<=n;r++)
		{
			long long sum=0,maxx=0;
			for(int i=l;i<=r;i++)
			{
				sum+=a[i];
				maxx=max(maxx,a[i]);
			}
			if(sum>maxx*2)
			{
				num++;
				for(int i=l;i<=r;i++)
				cout<<i<<" ";
				cout<<endl<<sum<<" "<<maxx;
				cout<<endl;
			}
			num%=998244353;
		}
	}
	cout<<num;
	return 0;
}
