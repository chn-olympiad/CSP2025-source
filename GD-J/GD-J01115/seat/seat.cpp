#include<bits/stdc++.h>
using namespace std;
struct intn
{
	int x=0;
	int y=0;
}a[105];
bool cmp(intn a,intn b)
{
	return a.x>b.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>m>>n;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		if(i==1)
		{
			a[i].y=1;
		}
		else
		{
			a[i].y=0;
		}
	 } 
	 sort(a+1,a+n*m+1,cmp);
	 int t=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[t].y==1)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				t++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[t].y==1)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				t++;
			}
		}
	}
	return 0;
 } 
