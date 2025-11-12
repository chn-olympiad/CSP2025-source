#include<bits/stdc++.h>
using namespace std;
long long n,k,b[500010]={0},c[500010],t=0,o,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k&&b[i]!=1) 
		{
			b[i]=1;
			t++;
		}
		if(b[i]==1) continue;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]^a[i-1]==k)
			{
				o=0;
				for(int u=i;u<=j;u++) 
				{
					if(b[u]!=0) 
					{
						o=1;
						break;
					}
				}
				if(o==1) continue;
				t++;
				for(int u=i;u<=j;u++) b[u]=1;
				break;
			}
		}
	}
	cout<<t;
	return 0;
} 
