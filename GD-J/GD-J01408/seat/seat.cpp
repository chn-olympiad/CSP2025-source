#include <bits/stdc++.h>
using namespace std;
int n,m,a[114],R,rk,r,c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)cin >> a[i];
	R=a[1];
	sort (a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==R)rk=i;
	c=ceil(1.0*rk/n);
	cout << ceil(1.0*rk/n) << ' ';
	if(c%2)cout << rk%(n+1);
	else cout << n-rk%(n+1);
}

