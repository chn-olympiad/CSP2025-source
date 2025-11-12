#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,b[n+1],a[n+1],l=0;
freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>b[i];
}
for(int i=3;i<=n;i++)
{
	for(int j=0;j<i;j++)
	{
		for(int k=1;k<=n;k++)
		{
			a[l]=b[k];
		}
	}
}
}