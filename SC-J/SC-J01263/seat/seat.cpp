#include<bits/stdc++.h>
using namespace std;
int n,m,flag,h,l;
struct node{
	int id,d;
}a[10010];
bool cmp(node a,node b){
	return a.d>b.d;
}
void dfs(int x,int y,int z)
{
	if(z==flag)
	{
		l=x;
		h=y;
		return;
	}
	if(x%2==1)//奇数行,下行
	{
		if(y+1<=n)dfs(x,y+1,z+1);
		else dfs(x+1,n,z+1);
	}
	else//偶数行，上行
	{
		if(y-1>=1)dfs(x,y-1,z+1);
		else dfs(x+1,1,z+1);
	}
	return;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].d;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			flag=i;
			break;
		}
	}
	dfs(1,1,1);
	cout<<l<<" "<<h;
	return 0;
}