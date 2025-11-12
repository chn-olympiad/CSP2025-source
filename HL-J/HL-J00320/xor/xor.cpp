#include<bits/stdc++.h>
#include<cstdio>
using namespace std;


int h;
int a[100005];
int qrt(int x,int y)
{
	for(int i=x;i<=y;i++)
	{
		h+=a[i];
	}
}
int n,max1,l;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int z=1;j<=i;z++)
			{
				l+=a[i];
				if(a[z]>max1) max1=a[z];
			}
			if(l>2*max1) l=(l+1)%1234;
		}
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}