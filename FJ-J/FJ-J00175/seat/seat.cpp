#include<bits/stdc++.h>
using namespace std;
int a[12][12],g[110],flag,n,m;
int dx[5]={0,1,-1};
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y,int cnt,int d)
{
	if(g[cnt]==flag)
	{
		cout<<y<<" "<<x;
		return ;
	}
	if(x==n&&d==1)d=2,y+=1,cnt+=1;
	if(x==1&&d==2)d=1,y+=1,cnt+=1;
	if(g[cnt]==flag)
	{
		cout<<y<<" "<<x;
		return ;
	}
	dfs(x+dx[d],y,cnt+1,d);
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>g[i];
	flag=g[1];
	sort(g+1,g+1+n*m,cmp);
	dfs(1,1,1,1);                      
	return 0;
}
