#include<bits/stdc++.h>
using namespace std;
struct node {
	long long fen,shi;
} a[102];
bool cmp(node x,node y) {
	return x.fen>y.fen;
}
long long n,m,cnt;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		for(long long j=1; j<=m; j++) {
			cin>>a[cnt++].fen;
			if(i==1&&j==1) a[cnt].shi=1;
			else a[cnt].shi=0;
		}
	}
	cnt=0;
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1; i<=n; i++) {
		if(i%2==1) {
			for(long long j=1; j<=m; j++) {
				if(a[cnt++].shi==1) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		} else {
			for(long long j=m; j>=1; j--) {
				if(a[cnt++].shi==1) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
