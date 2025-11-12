#include<bits/stdc++.h>
using namespace std;

int b[105];
int a[15][15];
int num;
int n,m;

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>b[1];
	num=b[1];
	for(int i=2; i<=n*m; i++) {
		cin>>b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	int cnt=0;
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				a[i][j]=b[++cnt];
				if(a[i][j]==num) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		} else {
			for(int j=n; j>=1; j--) {
				a[i][j]=b[++cnt];
				if(a[i][j]==num) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
3 3
6 5 8 7 9 4 3 2 1

2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
