#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,k;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int p=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			p++;
		}
	}
	int cnt=0,y;
	bool l=1;
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			if(l)
			{
				y=a[i];
				l=0;
			}
			else
			{
				y^=a[i];
			}
			if(y==k)
			{
				cnt++;
				l=1;
			}
		}
	}
	
	cnt=max(cnt,p);
	cout<<cnt;
	return 0;
}
