#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[50][50];
int a[9999];
int a1;
int z =1;
bool f(int a,int b)
{
	if(a>b)
	{
		return a>b;
	}
	return a<b;
	
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
	a1 = a[1];
	sort(a+1,a+1+n,f);
	for(int i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=m;j++)
			{
				arr[i][j] = a[z];
				z+=1;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				arr[i][j] = a[z];
				z+=1;
			}
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(arr[i][j] == a1)
			{
				cout<<i<<" "<<j;
			}
		}
		
	}
	return 0;
}
