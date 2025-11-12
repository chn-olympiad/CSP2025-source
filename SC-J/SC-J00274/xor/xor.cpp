#include<bits/stdc++.h>
using namespace std;
int n,k,s[500005],flag=0,a[50000000],b[50000000],flags=0,ans=0;
int m=0,x=0;
void breaks(int e,int m)
{
	if(e%2==1)
	{
		a[m]=e%2;
	}
	breaks(e/2,m+1);
}
void breakb(int e,int x)
{
	if(e%2==1)
	{
		b[x]=e%2;
	}
	breakb(e/2,x+1);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	flag=0;
    for(int i=0;i<n;i++)
    {
    	cin>>s[i];
    	if(s[i]==0&&k==0)
    	{
    		flag=1;
		}
	}
	if(flag=0)
	{
		cout<<0<<endl;
		return 0;
	}
	breakb;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			for(int q=i;q<j;q++)
			{
				breaks(s[q],0);
			}
			for(int p=0;p<m;p++)if(m!=n||a[m]!=b[x])
			{
				flags=1;
			}
			for(int q=0;q<m;q++)
			{
				a[m]=0;
			}
			for(int q=0;q<x;q++)
			{
				b[n]=0;
			}
			if(flags!=1)ans++;
		}
	}
	cout<<ans;
	return 0;
} 