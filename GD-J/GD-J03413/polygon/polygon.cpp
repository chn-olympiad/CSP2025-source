#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++)
	{
		for (int j=1;j<=(1<<(i-1));j++)
		{
			int sum=0;
			for (int k=0;k<=i-1;k++)
			{
				if ((1<<k)&j){
					sum+=a[k+1];
				}
			}
			if (sum>a[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
