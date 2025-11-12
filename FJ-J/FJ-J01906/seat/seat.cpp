#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[1000],b,x,y,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1,greater<>() );
	for(int i=1;i<=n*m;i++) if(b==a[i]) {
		c=i;break;
	}
	x=(c+n-1)/n;
	if(x%2==1) y=c%n;
	else y=n+1-c%n;
	if(y==0) y+=n;
	cout<<x<<' '<<y;
	return 0;
}
/*3 3
94 95 96 97 98 99 100 93 92*/
