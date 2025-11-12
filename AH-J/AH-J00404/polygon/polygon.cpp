#include<bits/stdc++.h>
using namespace std;

int n,s,a[1001];

int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]+a[k]>2*max(a[i],max(a[i],a[j])))
					s++;
			}
		}
	}
	cout<<s;
	return 0;
}
