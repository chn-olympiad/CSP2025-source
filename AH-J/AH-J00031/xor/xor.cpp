#include<bits/stdc++.h>
using namespace std;
long long n,k,s1,s2;
long long a[5005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				s1++;
			}
		}
		cout<<s1;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1)
			{
				s2++;
				i++;
			}
			else if(a[i]==0)
			{
				s2++;
			}
		}
		cout<<s2;
	}
	return 0;
}
