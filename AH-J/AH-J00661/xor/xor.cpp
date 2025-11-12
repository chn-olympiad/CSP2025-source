#include <bits/stdc++.h>
using namespace std;
int n,s=0,k;
int a[500001];
bool c(int x,int y)
{
	int m=0;
	for (int z=x;z<=y;z++)
	{
		m+=a[z];
	}
	if(m==k)return 1;
	else return 0;
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
		for(int j=1;j<=n-i+1;j++)
		{
		s+=c(j,j+i);
		}
	}
	cout<<s;
	return 0;
}
