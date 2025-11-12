#include<bits/stdc++.h>
using namespace std;
int sz;
int x,y;
bool cmp(int a,int b)
{
		return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[101][101],b[1001],l=0;
    for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			b[l]=a[i][j];
			l++;
		}
	}
	l=0;
	sz=a[1][1];
    sort(b,b+n*m,cmp);
    for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=n;j++)
		{
			a[i][j]=b[l];
			cout<<a[i][j]<<" ";
			l++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==sz)
			{
				y=j;
				if(i%2==1)
				{
					x=i;
				}
				else
				{	
					x=n-i+1;
				}
				cout<<x<<" "<<y;
				cout<<" "<<i<<" "<<j;
				return 0;
			}
		}
		
	}
    return 0;
}
