#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n,m,k=1,x,l=1,y,p;
int a[101][101],b[10001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	y=m*n;
	for(int i=1;i<=y;i++)
		cin>>b[i];
	x=b[1];
	sort(b+1,b+y+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j%2==1)
			{
				p=(j-k)*10+i;
				if(b[p]==x)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
			if(j%2==0)
			{
				p=j*n-i+1;
				if(b[p]==x)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	return 0;
}
