#include<bits/stdc++.h>
using namespace std;
int n,m;
struct o{
	int c,h;
}a[10005];
bool cmp(o a,o b)
{
	return a.c>b.c;
}
int s[105][105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].c;
		a[i].h=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int t=0,c,r;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				t++;
				if(a[t].h==1)
				{
					c=i;r=j;
				}
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				t++;
				if(a[t].h==1)
				{
					c=i;r=j;
				}
			}

		}
	}
	cout<<c<<" "<<r;
	return 0;
}