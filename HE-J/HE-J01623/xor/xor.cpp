#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,a[500005];
int ans=0;
char c='c';
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) 
		{
			m++;
			a[i]=c;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=c)
		{
			ans=a[i];
			if(a[i]==k)
			{
				m++;
				a[i]=c;
				ans=0;
			}
		}
	}
	cout<<m;
	return 0;
}
