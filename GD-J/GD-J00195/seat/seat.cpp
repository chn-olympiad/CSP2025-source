#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m;
struct node{
	int val, id;
}a[N];
int g[11][11];

cmp(node x,node y) {
	return x.val > y.val;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm = n*m;
	for(int i=1;i<=nm;i++) {
		cin>>a[i].val;
		a[i].id = i; 
	}
	sort(a+1, a+1+nm, cmp);
	int Index = 0;
	for(int i=1;i<=m;i++) {
		if(i%2 == 1) {
			for(int j=1;j<=n;j++) {
				if(a[++Index].id == 1) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else {
			for(int j=m;j>=1;j--) {
				if(a[++Index].id == 1) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
