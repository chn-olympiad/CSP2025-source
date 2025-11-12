#include<iostream>
#include<algorithm>
using namespace std;
int n,m,l,cnt,c[100],a[12][12];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>c[i];
	l=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
	  if(i%2==1)
		for(int j=1;j<=m;j++)
		{
			a[i][j]=c[++cnt];
			if(a[i][j]==l)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	  else
		for(int j=m;j>=1;j--)
		{
			a[i][j]=c[++cnt];
			if(a[i][j]==l)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
} 
