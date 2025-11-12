#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
struct node
{
	int sc;
	int k;
}a[105];
bool cmp(node x,node y)
{
	return x.sc>y.sc;
}
int x,y;
void dfs(int l,int h,bool d)
{
	if(a[++cnt].k==1) 
	{
		x=l,y=h;
		return;
	}
	if(h==n&&l==m&&d==0) return;
	if(h==1&&l==m&&d==1) return;
	if((h==n&&d==1)||(h==1&&d==0))
	{
		l++;
		d=!d;
		dfs(l,h,d);
		return;
	}
	if(d)
	{
		h++;
		dfs(l,h,d);
		return;
	}
	else
	{
		h--;
		dfs(l,h,d);
		return;
	}
	return;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].k=i;
	}
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1);
	cout<<x<<' '<<y;
	return 0;
}
