#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int res=a[1]; sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++) {
		if(a[i]==res) {
			cout<<y<<' '<<x<<'\n';
			return 0;
		}
		if(y&1) {
			x++;
			if(x>n) y++,x=n;
		} else {
			x--;
			if(x<1) y++,x=1;
		}
	}
	return 0;
}
