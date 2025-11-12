#include<bits/stdc++.h>
using namespace std;

int n,m;
int r,h,ansx,ansy;
int a[200010];
bool cmp(int x,int y){return x>y;}
void dfs(int x,int y,int cnt,int fx)
{
//	cout<<x<<" "<<y<<" "<<cnt<<" "<<fx<<"\n";
	if(cnt==h)
	{
		ansx=x;
		ansy=y;
	}
	if(cnt==n*m)
		return ;
	if(y+fx<1||y+fx>n)
	{
		x++;
		fx*=-1;
		dfs(x,y,cnt+1,fx);
	}
	else
		dfs(x,y+fx,cnt+1,fx);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r)
			h=i;
	dfs(1,1,1,1);
	cout<<ansx<<" "<<ansy<<"\n";
	return 0;
}