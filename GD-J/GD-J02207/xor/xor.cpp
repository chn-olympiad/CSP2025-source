#include<iostream>
using namespace std;
int n,k;
int a[500010],b[500010],ans=0;
bool c[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1] xor a[i];
		c[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(c[j]==0)
			{
				j=0;
				continue;
			}
			if((b[i] xor b[j-1])==k)
			{
				ans++;
				c[i]=0;
				j=0;
				continue;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
