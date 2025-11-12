#include<bits/stdc++.h>
using namespace std;
int x,m[110],n[20][20],y;
int dx[5]={-1,1,0},dy[5]={0,0,1};

void output()
{
	int s = m[1],sum = 0;
	sort(m+1,m+x*y+1,greater<int>());
	for(int i =1;i<=x*y;i++)
		if(m[i] == s)
			sum = i;
	for(int i =1;i<=x;i++)
		for(int j =1;j<=y;j++)
			if(n[i][j] == sum)
				cout << j <<" " <<i;
}

void dfs(int k,int sx,int sy)
{
	if(k == x * y)
		output();
	for(int i =0;i<3;i++)
	{
		int nx = sx +dx[i];
		int ny = sy + dy[i];
		if(nx > x || nx<1||ny>y||ny<1) continue;
		if(n[nx][ny]!=0) continue;
		n[nx][ny] = k+1;
		dfs(k+1,nx,ny);
	}
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> x >>y;
	for(int i =1;i<=x*y;i++)
		cin >> m[i];
	n[1][1] = 1;
	dfs(1,1,1);
	return 0;
}
