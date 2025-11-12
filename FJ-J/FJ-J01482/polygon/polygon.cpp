#include<bits/stdc++.h>
using namespace std;
int usp[505]={0};
int a[5000+5];
int cmp(int x,int y)
{
	return x<y;
}
bool check(int n)
{
	int sum=0;
	for(int i=1;i<=n-1;i++)
	{
		sum+=a[usp[i]];
	}
//	cout<<sum<<' '<<2*a[usp[n]]<<' '<<n<<endl;
	return sum>2*a[usp[n]];
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans;
	sort(a+1,a+n+1,cmp);
	if(n==3)
	{
		if(a[1]+a[2]>2*a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			usp[j]=j;
		}
		for(int z=i;z>=1;z--)
		{
			for(int j=n-i;j<=n-1;j++)
			{
				usp[z]++;
				if(check(i))
				{
					ans++;
					ans%=998244353;
				}
			}
		}
	}
	cout<<ans;
}
