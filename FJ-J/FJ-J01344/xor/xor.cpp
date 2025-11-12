#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],s,l,x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(i==2 && a[1]==k && a[2]==k)s--;
		if(a[i]==k && l==1)
		{
			s++;
			l=i;
		}
		for(int j=l;j<i;j++)
		{
			x=a[i];
			x^=a[j];
			if(x==k)
			{
				s++;
				l=i;
				break;
			}
		}
	}
	cout<<s;
	return 0;	
} 
