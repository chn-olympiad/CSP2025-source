#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105];
int ans[15][15];
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
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=0,cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(k<1)
		{
			k++;
			while(k<=m) ans[i][k++]=a[cnt++];
		}
		else if(k>m)
		{
			k--;
			while(k>=1) ans[i][k--]=a[cnt++];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==x)
			{
				cout<<i<<" "<<j<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
