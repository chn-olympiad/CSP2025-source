#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
void dfs(int s)
{
	bool flag=true;
	int x=1,y=1;
	int i=1;
	for(;flag;)
	{
		while(y<m)
		{
			if(i==s)
			{
				flag=false;
				break;
			}
			y++;
			i++;
		}
		if(i==s)break;
		if(flag)
		{
			x+=1;
			i++;
		}
		while(y>1)
		{
			if(i==s)
			{
				flag=false;
				break;
			}
			y--;
			i++;
		}
		if(i==s)break;
		if(flag)
		{
			x+=1;
			i++;
		}
	}
	cout<<x<<' '<<y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=1,maxx;
	for(int i=1;i<=n*m;i++)
	{
		int x;
		cin>>x;
		if(i==1)maxx=x;
		else if(maxx<x)
		{
			cnt++;
		}
	}
	dfs(cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
