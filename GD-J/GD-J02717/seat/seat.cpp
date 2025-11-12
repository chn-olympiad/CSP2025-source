#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N],b[50][50];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,i,j,k=0,p;
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=m;i++)
		if(i&1)
		{
			for(j=1;j<=n;j++)
				b[i][j]=a[++k]; 
		}
		else
		{
			for(j=n;j>=1;j--)
				b[i][j]=a[++k];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[i][j]==p)
			{
				cout<<i<<' '<<j;
				return 0;
			}
	return 0;
}

