#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10009],v,x=1,y=1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (long long i=1; i<=n*m; i++) cin >> a[i];
	v=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (long long i=1; i<=n*m; i++){
		if (a[i]==v){
			cout << y << " " << x;
			return 0;
		}
		if (y%2==1) x++;
		else x--;
		if (x==0) y++,x=1;
		if (x==n+1) y++,x=n;
	}
	return 0;
}
