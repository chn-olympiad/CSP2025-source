#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int n,m,c,w;
int a[N];
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)cin>>a[i];
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==c) {
			w=i;
			break;
		}
	}
	int x=0,y=0;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			w--;
			if(!w) {
				y=i,x=j;
				break;
			}
		}
	}
	if(y&1)cout<<y<<" "<<x;
	else cout<<y<<" "<<n-x+1;
	return 0;
}
/*
2 2
99 100 97 98

1 2

2 2
98 99 100 97

2 2
*/
