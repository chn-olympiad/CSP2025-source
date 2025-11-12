#include<bits/stdc++.h>
using namespace std;
int n,m,a,R,sum=1,c,r;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>R;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>R) sum++;
	}
	c=(sum+n-1)/n;
	r=(sum%n==0?n:sum%n);
	r=(c%2==0?n-r+1:r);
	cout<<c<<' '<<r;
	return 0;
}
