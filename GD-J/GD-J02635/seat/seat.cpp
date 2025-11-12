#include<bits/stdc++.h>
using namespace std;

int a[120];
int ans[12][12];
int n,m,tgt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	tgt=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int j=0,ct=1;
	while(j<=m)
	{
		j+=1;
		if(j%2!=0)
		{
			for(int i=1;i<=n;i++)
			{
				ans[i][j]=a[ct];
				ct+=1;
			}
			continue;
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				ans[i][j]=a[ct];
				ct+=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==tgt)
			{
				cout<<j<<" "<<i;
			}
		}
	}	
	return 0;
} 
