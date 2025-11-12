#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[20][20];
int b[1000];
int r;
int t;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin>>b[i];
	}
	r=b[1];
	sort(b+1,b+t+1,cmp);
	for(int i=1,k=1,j=1;k<=t;k++)
	{
		a[i][j]=b[k];
		if(j%2==1)
		{
			if(i<n)
			{
				i++;
			}
			else
			{
				j++;
			}
		}
		else
		{
			if(i>1)
			{
				i--;
			}
			else
			{
				j++;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			//if(a[i][j]==r)
//			{
//				cout<<a[i][j]<<" ";
//				
//			}
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==r)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
