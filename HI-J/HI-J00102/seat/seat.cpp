#include"bits/stdc++.h"
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans;
	bool t=0;
	cin>>n>>m;
	int b[n+5][m+5],a[10010]; 
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	ans=a[1];
	for(int i=1;i<=n*m;i++)
	for(int j=i+1;j<=n*m;j++)
		if(a[i]<a[j]) swap(a[i],a[j]);
	for(int j=1;j<=m;j++)//ап
	{
		for(int i=1;i<=n;i++)
		{
			if(t==0)
			{
				for(int z=(j-1)*n+1;z<=n*j;z++)
				{
					b[j][i]=a[z];
					i++;
				}
				t=1;
				continue;
			}
			else if(t==1)
			{
				for(int z=n*j;z>=n*(j-1)+1;z--)
				{
					b[j][i]=a[z];
					i++;
				}
				t=0;
				continue;
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		if(b[j][i]==ans) 
		{
			cout<<j<<" "<<i;
			break;
		}
		cout<<endl;
	}
	return 0;
 } 
