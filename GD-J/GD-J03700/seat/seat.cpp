#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],a1,ox,oy,i;
bool cmp (long long ab,long long bb) {
	return ab>bb;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=1;i<=(n*m);i++) {
		cin>>a[i];
		if (i==1) a1=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	i=1;
	while (a[i]>a1) i++;
	ox=(i-1)/n+1;
	oy=(i-1)%n;
	if (ox%2==0) oy=n-oy;
	else oy++;
	cout<<ox<<" "<<oy;
	return 0;
}

