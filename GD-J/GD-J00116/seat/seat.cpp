#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int y=lower_bound(a+1,a+n*m+1,x,greater<int>())-a;
	int r=(y-1)%n+1,c=ceil(1.0*y/n);
	if(c%2==0)r=n+1-r;
	cout<<c<<" "<<r;
	return 0;
}
