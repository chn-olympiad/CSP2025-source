#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,s[N],z,c,d;
struct node{
	int x,y;
}a[N];
bool cmp(node c,node b){
	return c.x>b.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
	cin>>a[i].x;
	a[i].y=i;		
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i].y==1)
		z=i;
	}
	c=ceil(z*1.0/n);
	if (c%2==1)
	{
		d=z-n*(c-1);
	}
	else d=n-(z-n*(c-1))+1;
	cout<<c<<" "<<d;
	return 0;
}
