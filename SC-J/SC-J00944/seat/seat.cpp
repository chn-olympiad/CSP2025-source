#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],sx,sy;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y,int s,int d)
{
//	cout<<x<<' '<<y<<' '<<s<<' '<<d<<'\n';
	if(s==0)
	{
		sx=x,sy=y;
		return;
	}
	if(d==0)
	{
		if(y+1>n)
			dfs(x+1,y,s-1,1);
		else
			dfs(x,y+1,s-1,0);
	}
	else
	{
		if(y-1<1)
			dfs(x+1,y,s-1,0);
		else
			dfs(x,y-1,s-1,1);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1],num;
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i]<<' ';
//	cout<<'\n';
	for(int i=1;i<=n*m;i++)
		if(x==a[i])
		{
			num=i;
			break;
		}
//	cout<<num<<'\n';
	dfs(1,1,num-1,0);
	cout<<sx<<' '<<sy;
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/