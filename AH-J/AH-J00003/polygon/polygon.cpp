#include<bits/stdc++.h>
using namespace std;
int n,s=0,a[10000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(2*a[k]<a[i]+a[j]+a[k]) s++;
			}
		}
	}
	cout<<s;
	return 0;
}
