#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int f=n;
	int b=a[1],c=a[n],d=-1;
	while(f>0)
	{
		for(int k=1;k<=n;k++)
		{
			for(int i=k;i<=f;i++)
	    	{
			    b&=a[i];
	    	}
			if(b==m) d=max(f-k,d);
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=f;i>=k;i--)
	    	{
			    c&=a[i];
			    if(c==m) d=max(f-k,c);
	    	}
		}
		f--;
		c=a[f];
		b=a[n-f];
	}
	cout<<d;
    fclose(stdin);
    fclose(stdout);
	return 0;
} 
