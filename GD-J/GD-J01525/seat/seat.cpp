#include<bits/stdc++.h>
using namespace std;
struct node {
	int id,fen;
} a[1000010],b[1000010][1000010];
bool cmp(node x,node y) {
	return x.fen>y.fen;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	cin>>n>>m;
	for(int i = 1; i<=n*m; i++) {
		cin>>a[i].fen;
		a[i].id = i;
	}
	int u = 0;
	bool jk = 0,lo = 0;
	int o = 0,r = 1;
	sort(a+1,a+1+n * m,cmp);
	for(int i = 1; i<=m; i++) {
		if(jk == 1 || o > m) break;
		o++;
		for(int j = 1; j<=n; j++) {

			u++;
			b[o][r].fen = a[u].fen;
			b[o][r].id = a[u].id;
			if(a[u].id == 1) {
				cout<<o<<" "<<r++;//<<" "<<u;
				jk = 1;
				break;
			}
			if(lo == 1) r--;
			else r++;

		}
		if(lo == 0) {
			r = n;
			lo = 1;
		} else {
			lo = 0;
			r = 1;
		}

	}
	return 0;
}
