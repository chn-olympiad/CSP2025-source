#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+3;
int a[N],n,m,g,l=1;
bool cmp(int x,int y) {
	return x>y;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int j1=n*m;
	for(int i=1; i<=j1; i++) {
		cin>>a[i];
		g=a[1];
	}
	sort(a+1,a+1+j1,cmp);
	int j=1;
	for(int i=1; i<=m; i++) {
		if(j==1) {
			while(j<=n) {
				if(a[l]==g) {
					cout<<i<<' '<<j;
					return 0;
				}
				++j,++l;
			}
			--j;
		}
		else if(j==n) {
			while(j>=1) {
				if(a[l]==g) {
					cout<<i<<' '<<j;
					return 0;
				}
				--j,++l;
			}
			++j;
		}
	}
	return 0;
}



