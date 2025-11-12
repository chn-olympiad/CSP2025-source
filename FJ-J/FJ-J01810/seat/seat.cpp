#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans,c,nxt;
int w;
int a[105][105];
int s[1005];
bool cmp(double x,double y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>s[i];
	}
	w=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=m*n;++i)
	{
		if (s[i]==w)
		{
			ans=i;
			break;
		}
	}
	c=0;
	nxt=0;
	for(int i=1;i<=m;++i)
	{
		if (nxt==0 || nxt==1)
		{
			for(int j=1;j<=n;++j)
			{
				c+=1;
				if (c==ans)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
			nxt=n;
		}
		else
		{
			for(int j=n;j>0;--j)
			{
				c+=1;
				if (c==ans)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
			nxt=1;
		}
	}	
}
