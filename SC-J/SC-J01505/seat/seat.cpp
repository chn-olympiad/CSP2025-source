#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int g[105][105];
int a[N];
int n,m,k,idx;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y,bool fwd,int w)
{
	if(w==idx)
	{
		cout<<y<<" "<<x;
		return;
	}
	if(fwd==0)
	{
		if(x==n)
		{
			dfs(x,y+1,1,w+1);
		}
		else 
		{
			dfs(x+1,y,0,w+1);
		}
	}
	else{
		if(x==1)
		{
			dfs(x,y+1,0,w+1);
		}
		else dfs(x-1,y,1,w+1);
	}
}
main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			idx=i;
			break;
		}
	}
	dfs(1,1,0,1);
	
	return 0;
}//少羽牛逼