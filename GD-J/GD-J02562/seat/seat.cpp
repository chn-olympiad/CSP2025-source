#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,uuu;
ll o[1001][1001];
ll p[100001],cnt;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>p[++cnt];
		if(cnt==1) uuu=p[i];
	}
	sort(p+1,p+cnt+1,cmp);
	int x=1,y=1,t=0;
	while(t<=cnt)
	{
		t++;
		o[x][y]=p[t];
		if(t%n==0) y++;
		else if(y%2!=0)
		{
			x++;
		}
		else if(y%2==0)
		{
			x--;
		}
		
	}
	o[1][1]=p[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(o[i][j]==uuu)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}

