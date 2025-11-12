#include<bits/stdc++.h>
using namespace std;
int n,m,z;
struct chenji {
	int fenshu;
	int who;
} a[110];
bool cmp(chenji x,chenji y) {
	return x.fenshu>y.fenshu;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].fenshu;
		a[i].who=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=m; i++) {
		if(i%2) {
			for(int j=1; j<=n; j++) {
				z++;
				if(a[z].who==1) {
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		} else {
			for(int j=n; j>=1; j--) {
				z++;
				if(a[z].who==1) {
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
