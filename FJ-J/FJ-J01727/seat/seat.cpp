#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300];
int ans[20][20];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int keyy=a[1];
	int k=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				ans[j][i]=a[k++];
			}
		}
		else 
		{
			for(int j=n;j>0;j--)
			{
				ans[j][i]=a[k++];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(ans[i][j]==keyy)
				cout<<j<<" "<<i;
	}
	return 0;
} 
