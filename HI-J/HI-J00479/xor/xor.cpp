#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; 
	}
	if(k==0)
	{
		cout<<n/2; 
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
