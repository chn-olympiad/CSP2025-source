#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],s[15][15],cnt,len,g,d;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len = n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
	}
	g = a[1];
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++)
	{
		if(a[i] == g)
		{
			d = i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				s[i][j] = ++cnt;
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				s[i][j] = ++cnt;
			}
		}	
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(s[i][j] == d)
				{
					cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if(s[i][j] == d)
				{
					cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}	
	}
	return 0;
}

