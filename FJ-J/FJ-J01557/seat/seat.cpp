#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],t,t1,d;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	d=2*n;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==t)
			t1=i;
	int p=t1/d;
	if(t1%d==0)
		cout<<2*p<<" "<<1;
	else if(t1%d<=n)
		cout<<2*p+1<<" "<<t1%d;
	else
		cout<<2*p+2<<" "<<n-t1%n+1;
	return 0;
}