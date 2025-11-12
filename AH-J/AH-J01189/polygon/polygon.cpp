#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<(1<<(i-1));j++)
		{
			if(__builtin_popcount(j)<=1)
				continue;
			int sum=0;
			for(int k=1;k<=i;k++)
				if(j&(1<<(k-1)))
					sum+=a[k];
			if(sum>a[i])
			{
				cout<<i<<' '<<j<<'\n';
				ans++;
			}
		}
	}
	cout<<ans;
}
