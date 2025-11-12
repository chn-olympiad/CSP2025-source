#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,c,r,k1,k2;
int cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==t)
		{
			t=i;
			break;
		}
	if(t%n==0)
		c=t/n,r=n;
	else
		c=t/n+1,r=t%n;
	if(c%2==0)
		cout<<c<<" "<<n-r+1;
	else
		cout<<c<<" "<<r;
	
	return 0;
}
