#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int b[105][105];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105]={0},sum=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
		cin>>a[i];
	}
	int p=a[1];
	int t=n*m;
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++)
	{
		sum++;
		if(a[i]==p)
		{
			break;
		}
	}
	int x=1,y=1,cnt=0;
	for(int i=1;i<=t;i++)
	{
		b[x][y]=i;
		if(b[x][y]==sum)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(x!=n&&cnt==0)
		{
			x++;
		}
		else if(x==n&&cnt==0)
		{
			y++;
			cnt=1;
		}
		else if(x!=1&&cnt==1)
		{
			x--;
		}
		else if(x==1&&cnt==1)
		{
			y++;
			cnt=0;
		}
	}
    return 0;
}

