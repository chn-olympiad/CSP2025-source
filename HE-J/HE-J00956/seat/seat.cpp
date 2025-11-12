#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],idx[210],lastid;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int id=n*m;
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				a[j][i]=id;
				id--;
			}
		} else {
			for(int j=n; j>=1; j--) {
				a[j][i]=id;
				id--;
			}
		}
	}
	for(int i=1; i<=n*m; i++)
		cin>>idx[i];
	int xid=idx[1];
	sort(idx+1,idx+1+n*m);
	for(int i=n*m; i>=1; i--) {
		if(idx[i]==xid) {
			lastid=i;
			break;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]==lastid) {
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
