#include<bits/stdc++.h>
using namespace std;
int n,k,ans,sum,j;
int a[500005];
bool q=true;
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
		q=true;
		if(a[i]==k)
		{
			ans++;
			continue; 
		}
		else
		{
			sum=a[i];
			j=i;
			while(sum!=k)
			{
				i++;
				sum^=a[i];
				if(i==n&&sum!=k)
				{
					q=false;
					break;
				}
			}
			if(q==true)
			{
				ans++;
			}
			else
			{
				i=++j;
			}
		}
	}
	cout<<ans;
	return 0;
}
