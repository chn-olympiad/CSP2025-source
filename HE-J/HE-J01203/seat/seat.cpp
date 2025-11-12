#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int b[110];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m;) {
			int u=0;
			c++;
			//sort(b[c],b[c+1]);
			b[c]=a[i][j];
			if(i=n) {
				j++;
			}
		}
	}
	for(int i=1; i<=n; i++)
		return 0;
}
