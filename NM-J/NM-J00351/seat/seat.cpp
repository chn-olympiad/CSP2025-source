#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int l,int r)
{
	return l>r;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,zong,x,y;
	cin>>n>>m;
	zong=n*m;
	for(int i=1;i<=zong;i++) cin>>a[i];
	int fs=a[1];
	sort(a+1,a+zong+1,cmp);
	int p=1;
	while(a[p]!=fs) p++;
	if(p%n==0) y=p/n;
	else y=p/n+1;
	if(y%2==1)
	{
		if(p%n==0) x=n;
		else x=p%n;
	}
	else
	{
		if(p%n==0) x=1;
		else x=n-p%n+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
