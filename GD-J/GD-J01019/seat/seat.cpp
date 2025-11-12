#include <bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,a[N],r,c,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=1;i<=n*m;i++)if(a[i]>a[1])cnt++;
	r=cnt/n+1;
	c=(r%2==1?cnt%n+1:n-cnt%n);
	cout<<r<<' '<<c;
	return 0;
}

