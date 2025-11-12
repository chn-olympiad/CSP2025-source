#include <bits/stdc++.h>
#define endl '\n';
#define ll long long 
using namespace std;
int n,m;
struct node{
	int a,id,x,y;
}a[400];
bool cmp1(node x,node y) {
	return x.a>y.a;
}
bool cmp2(node x,node y) {
	return x.id<y.id;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> a[(i-1)*n+j].a;
			a[(i-1)*n+j].id=(i-1)*n+j;
		}
	}
	sort(a+1,a+n*m+1,cmp1);
	int now=0,i=1,j=1;
	while(now<n*m) {
		a[++now].x=i,a[now].y=j;
		if(i%2) {
			if(j==n) i++;
			else j++;
		}
		else {
			if(j==1) i++;
			else j--;
		}
	}
	sort(a+1,a+n*m+1,cmp2);
	cout << a[1].x << " " << a[1].y;
	return 0;
}
