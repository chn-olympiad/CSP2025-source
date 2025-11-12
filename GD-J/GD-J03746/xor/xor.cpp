#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool li[10005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k && li[i]==0)
		{
			ans++;
			li[i]=1;
		}
		else
		{
			int check=1,check1=a[i];
			while(1)
			{
				if(check+i>n)break;
				if(li[check+i]==1)break;
				for(int j=1;j<=check;j++)
				{
					check1=check1^a[i+j];
				}

				if(check1==k)
				{
					ans++;
					for(int j=i;j<=i+check;j++)
					{
						li[j]=1;
					}
					break;
				}
				else check++;
			}
		}
	}
	cout<<ans;
	return 0;
}
