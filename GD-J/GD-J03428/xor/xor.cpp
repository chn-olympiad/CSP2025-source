#include <iostream>
#include <cstdio>
using namespace std;
int n,k,cnt;
int a[100005];
bool b[100005];

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
		for(int j=1;j<=n-i+1;j++)
		{
			int sum=0;
			bool flag=1;
			for(int w=1;w<=i;w++)
			{
				if(b[j+w-1])
				{
					flag=0;
					break;
				}
				sum^=a[j+w-1];
			}
			if(sum==k&&flag)
			{
				
				cnt++;
				for(int w=1;w<=i;w++)
				{
					b[j+w-1]=!b[j+w-1];
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
