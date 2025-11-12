#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int n,m,a[N],op;
inline void solve() {
	int dx=0,dy=0;
	sort(a+1,a+1+n*m);
	for(int i=n*m; i>=1; i--) {
		if(dy%2!=0) {
			if(dx+1>n) {
				dy++;
				dx=n;
				if(a[i]==op) {
					cout<<dy<<" "<<dx;
					return;
				}
				continue;
			}
			dx++;
		}
		else if(dy%2==0) {
			if(dx-1<1) {
				dy++;
				dx=1;
				if(a[i]==op) {
					cout<<dy<<" "<<dx;
					return;
				}
				continue;
			}
			dx--;
		}
		if(a[i]==op) {
			cout<<dy<<" "<<dx;
			return;
		}
	}
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		cin>>a[i];
	op=a[1];
	solve();
	return 0;
}
