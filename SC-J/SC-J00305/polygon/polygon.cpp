#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],maxn;
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygen.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		ans=0;
		cout<<ans;
		return 0;
	}
	bool vis[N];
	for(int picks=3;picks<=n;picks++)
	{
		int times=0;
		for(int i=1;i<=n;i++)
		{
			
			times=1;
			for(int j=1;j<=i;j++)
			vis[j]=1;
			for(int j=i;j<=n;j++)
			{
				if(times>picks)
				{
					break;
				}
				if(vis[j])
				{
					continue;
				}
				else
				{
				vis[j]=1;
				sum+=a[j];
				maxn=max(a[j],maxn);
				times++;					
				}
			}
			if(sum>maxn*2)
			{
				ans++;
				cout<<sum<<" ";
				ans%=998244353;
			}
		}
	}
	cout<<ans;
	return 0;
}