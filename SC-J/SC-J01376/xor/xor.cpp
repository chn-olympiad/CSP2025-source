#include <bits/stdc++.h>
using namespace std;
int b[500000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int sum=a[i];
			if(i==j)
			{
				if(a[i]==k&&!b[i])
				{
					num++;
					b[i]=1;
					break;
				}
			}
			for(int l=i;l<=j;l++)
			{
				int s=sum&a[l];
				sum=(sum|a[l])+s;
			}
			if(sum==k&&!b[i])
			{
				num++;
				b[i]=1;
				break;
			}
		}
	}
	cout<<num;
	return 0; 
}