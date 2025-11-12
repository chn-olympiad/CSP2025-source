#include <bits/stdc++.h>
using namespace std;
int a[105],n,m;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r","stdin");
	freopen ("seat.out","w","stdout");
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int xiaom=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) {
		cout<<a[i]<<" ";
	}
	int y=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			y++;
			if(a[y]==xiaom) {
				if(i%2==0) cout<<i<<" "<<m-j+1;
				else cout<<i<<" "<<j;
			}

		}
	}
	return 0;
}
