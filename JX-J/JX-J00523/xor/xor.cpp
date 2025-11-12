#include<bits/stdc++.h>
using namespace std;
bool flag[100001]={};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k,a[100001],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int c=a[i];
			for(int b=i+1;b<=j;b++)
			{
				c^=a[b];
			}
			if(i==j&&a[i]==k&&!flag[i])
			{
				ans++;
				flag[i]=true;
			}
			else if(i!=j&&c==k)
			{
				bool bl=true;
				for(int b=i;b<=j;b++)
				{
					if(flag[b])
					{
						bl=false;
						break;
					}
				}
				if(bl)
				{
					ans++;
					for(int b=i;b<=j;b++)
					{
						flag[b]=true;
					}
				}
					
			}	
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
