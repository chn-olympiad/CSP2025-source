#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int gs=a[1],seat;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==gs)seat=i;
	c=seat%n==0?seat/n:seat/n+1;
	if(c%2==0)
	{
		if(seat%n==0) r=1;
		else r=n-seat%n+1;
	}else
	{
		r=seat%n==0?n:seat%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
