#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[105],b,rnk;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(b==a[i])rnk=n*m+1-i;
	x=(rnk-1)/n;
	if(x&1)y=n+1-(rnk-x*n);
	else y=(rnk-x*n);
	x++;
	cout<<x<<" "<<y;
	return 0;
}
