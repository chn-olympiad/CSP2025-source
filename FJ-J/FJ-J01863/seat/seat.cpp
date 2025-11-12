#include<bits/stdc++.h>
using namespace std;
const int N=1e2+2;
int n,m,a[N],r,p,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m);
	p=n*m-(lower_bound(a+1,a+1+n*m,r)-a)+1;
	l=(p-1)/n+1;
	if(l%2)h=p-(l-1)*n;
	else h=n-(p-(l-1)*n)+1;
	cout<<l<<' '<<h;
	return 0;
}

