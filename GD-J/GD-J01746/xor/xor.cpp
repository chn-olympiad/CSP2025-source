#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],b[1000005],t;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int s=a[i];
		if(s==k)
		{
			t++;
			b[i]=1;
			continue;
		}
		for(int j=i+1;j<n;j++)
		{
			if(b[j]==1)
			{
				break;
			}
			s=s^a[j];
			if(s==k)
			{
				t++;
				for(int ll=i;ll<=j;ll++)
				{
					b[ll]=1;
				}
				i=i+j;
				break;
			}
		}
	}
	cout<<t;
	return 0;
 } 
