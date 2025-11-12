#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				if(a[i]==k)ans++;
				continue;
			}
			if(a[i]+a[j]==k)ans++;
		}
	}
	cout<<ans;
} 
