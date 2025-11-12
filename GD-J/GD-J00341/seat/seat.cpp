#include<bits/stdc++.h>
using namespace std;
int h[1000];
int x=1;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >>h[x++];
		}
	}
	for(int i=1; i<=x; i++) {
		cout <<h[i]<<" ";
	}
	cout <<endl;
	int ax=h[1];
	sort(h+1,h+1+x,cmp);
	for(int i=1; i<=x; i++) {
		cout <<h[i]<<" ";
	}
	cout <<endl;
	int a[101][101];
	int k=1;
	for(int i=1; i<=m; i++) {
		if(i%2==0) {
			for(int j=n; j>=1; j--) {
				a[j][i]=h[k];
				k++;
			}
		} else {
			for(int j=1; j<=n; j++) {
				a[j][i]=h[k];
				k++;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout <<a[i][j]<<" ";
		}
		cout <<endl;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]==ax) {
				cout <<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

