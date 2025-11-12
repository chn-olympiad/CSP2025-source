#include<bits/stdc++.h>
#include<windows.h>
typedef int int32;
#define int long long
using namespace std;
/*
	Author: wbw_121124
	»ÀΩ‹µÿ¡È
	game.cpp
*/
const int N = 50 + 5;
int n=5,m=5,a[N][N],dx[]={0,0,1,-1},dy[]={1,-1,0,0},last=-1;
mt19937 gen(time(0)^clock());
vector<pair<int,int>>to;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=(i-1)*m+j;
	a[n][m]=0;
	for(int i=1;i<=n*m*5;i++)
	{
		bool f=true;
		for(int i=1;i<=n&&f;i++)
			for(int j=1;j<=m;j++)
				if(!a[i][j])
				{
					int tmp=gen()%4;
					while(i+dx[tmp]<1||j+dy[tmp]<1||i+dx[tmp]>n||
						j+dy[tmp]>m)
						tmp=gen()%4;
					to.push_back({i,j});
					swap(a[i][j],a[i+dx[tmp]][j+dy[tmp]]);
					f=false;
					break;
				}
	}
	for(int _=0;_<n*m*5;_++)
	{
		for(int i=1;i<=n;i++,cout<<'\n')
			for(int j=1;j<=m;j++)
				cout<<a[i][j]<<'\t';
		cout.flush();
		bool f=true;
		for(int i=1;i<=n&&f;i++)
			for(int j=1;j<=m;j++)
				if(!a[i][j])
				{
					swap(a[i][j],a[to.back().first][to.back().second]);
					to.pop_back();
					f=false;
					break;
				}
		Sleep(50);
		system("cls");
	}
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=m;j++)
			cout<<a[i][j]<<'\t';
	cout.flush();
	return 0;
}
