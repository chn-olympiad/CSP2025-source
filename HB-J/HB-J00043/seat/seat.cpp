#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,num,a[N];
int cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y,int step,int d)
{
	if(a[step]==num)
	{
		cout << y << ' ' << x;
		return ;
	}
	if(d==1)
	{
		if(x+1>n)
			dfs(x,y+1,step+1,-1);
		else
			dfs(x+1,y,step+1,1);
	}
	else
	{
		if(x-1<1)
			dfs(x,y+1,step+1,1);
		else
			dfs(x-1,y,step+1,-1);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1,1);
	return 0;
}
