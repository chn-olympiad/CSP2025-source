#include <bits/stdc++.h>
#define z 787891
using namespace std;
int n,k,ans,lst;
bool flag;
int a[z],b[z],c;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			ans++;
			c=0;
			continue;
		}	
		else
		{
			c^=a[i];
			if(c==k)
			{
				ans++;
				c=0;
			}	
		}
	}
	cout<<ans;	
	return 0;
}

