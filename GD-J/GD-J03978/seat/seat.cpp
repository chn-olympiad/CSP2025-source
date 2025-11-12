#include<bits/stdc++.h>
using namespace std;
int n,m;
int val[100010];
int s = 0;
int seat[1001][1001];
bool tmp(int a,int b)
{
	if(a > b || a == b) 
	return true;
	else
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++)
	{
		cin>>val[i];
	}
	s = val[1];
	int idx = 0;
	sort(val + 1,val + (n * m) + 1,tmp);
	for(int i = 1;i <= m; i ++)
	{
		if(i % 2 == 1)
		for(int j = 1;j <= m;j ++)
		{
			seat[i][j] = val[++idx];
		}
		if(i % 2 == 0)
		for(int j = n;j >= 1;j --)
		{
			seat[i][j] = val[++idx];
		}
	}
	for(int i = 1;i <= n;i ++)
	for(int j = 1;j <= m;j ++)
	{
		if(seat[i][j] == s)
		{
			cout<<i<<' '<<j<<endl;
			return 0;
		}
	}
	return 0;
}
