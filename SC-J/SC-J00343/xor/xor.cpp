#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500020],m,q=1;
int x(int i,int j)
{
	int y=a[j];
	for(int z=j+1;z<=i;z++)
	{
		y^=a[z];
	}
	return y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=q;j<=i;j++)
		{
			if(x(i,j)==k)
			{
				m++;
				q=i+1;
				j=i+1;
			}
		}
	}
	cout<<m;
	return 0;
}