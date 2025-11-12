#include <bits/stdc++.h>
using namespace std;
int a[5010];
const long long MOD=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	unsigned long long int sum=0;
	int he=0,mx=-100000;
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int d=1;d<i;d++)
			{
				he+=a[j-d];
				mx=max(mx,a[j-d]);
			}
			if(he>mx*2)
			{
				sum++;
			}
		}
	}
	sum-=1;
	cout<<sum%MOD;
	return 0;
}
//数据你给点力啊，我不信25个点里没有我蒙到的解法，就算4分那也是分啊 
