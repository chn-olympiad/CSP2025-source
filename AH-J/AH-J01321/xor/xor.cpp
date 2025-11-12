#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans=0;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else if(a[i]==a[i+1])
			{
				ans++;
				i++;
			}
		}
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
			else if(a[i]==a[i+1]+1||a[i]==a[i+1]-1)
			{
				ans++;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 0
2 1 0 3
*/
