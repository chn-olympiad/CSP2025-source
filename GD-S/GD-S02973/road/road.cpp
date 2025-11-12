#include<bits/stdc++.h>
using namespace std;
int a[10006][10006],b[10006][10006],n,m,c,x,y,d;
int main()
{
	cin>>n>>m>>c;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>d;
		a[x][y]=d;
		a[y][x]=d;
	}
	
}

