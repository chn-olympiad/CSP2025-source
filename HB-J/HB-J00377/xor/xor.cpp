#include<bits/stdc++.h>
using namespace std;
int a[200005],book[200005],sum,n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;)
	{
		if(k==1)
		{
			if(a[i]!=a[i+1]&&book[i]!=1&&book[i+1]!=1)
			{
				sum++;
				book[i]=1;
				book[i+1]=1;
				i+=2;
				continue;
			}
			else if(a[i]==1)
			{
				sum++;
				book[i]=1;
			}
			i++;
		}
		if(k==0)
		{
			if(a[i]==a[i+1]&&book[i]!=1&&book[i+1]!=1)
			{
				sum++;
				book[i]=1;
				book[i+1]=1;
				i+=2;
				continue;
			}
			else if(a[i]==0)
			{
				sum++;
				book[i]=1;
			}
			i++;
		}
		
	}
	cout<<sum;
	return 0;
}
