#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,m;
struct node {
	int x,id;
}a[10005];
bool cmp(node a,node b) {
	return a.x>b.x;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i ++) cin >> a[i].x,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int x=1,y=1,c=1,i=1;1;i ++) {
		if(a[i].id==1) return cout << x << " " << y,0;
		y+=c;
		if(y>n) x++,y=n,c=-1;
		if(y<1) x++,y=1,c=1;
	}
	return 0;
}
