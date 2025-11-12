#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],flag,order,ans1,ans2;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	flag=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(flag==a[i]) order=i;
	}
	if(order%n==0) ans1=order/n;
	else ans1=order/n+1;
	if(ans1%2==1) 
	{
		if(order%n==0) ans2=n;
		else ans2=order%n;
	}
	else
	{
		ans2=ans1*n-order+1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
