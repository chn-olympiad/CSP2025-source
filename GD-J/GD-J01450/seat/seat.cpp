#include<iostream>
//#include<algorithm>
using namespace std;
int n,m,a[15][15],b[15][15],c[101],d[15],e[15][15],i,j,k=1,l=1,sum=1;
//bool cmp(int x,int y) {
//	return x>y;
//}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for( i=1; i<=n; i++) {
		for( j=1; j<=m; j++) {
			cin>>a[i][j];
			c[a[i][j]]++;
		}
	}
//	sort(a,a+n+m,cmp);
	for(int u=100; u>=1; u--) {
		if(c[u]>0) {
			d[sum]=u;
			sum++;
		}
	}
	sum=1;
	for(int x=1; x<=n; x++) {
		for(int y=1; y<=m; y++) {
			if(d[sum]>0) {
				e[x][y]=d[sum];
				sum++;
			}
		}
	}
	j=1;
	for(i=1; i<=m; i++) {
		k=1;
		if(j==1) {
			for(; j<=n; j++) {
				b[j][i]=e[l][k];
				k++;
			}
		} else {
			for(; j>=1; j--) {
				b[j][i]=e[l][k];
				k++;
			}
		}
		l++;

	}
	for(int o=1; o<=n; o++) {
		for(int p=1; p<=m; p++) {
			if(b[o][p]==a[1][1]) {
				cout<<p<<' '<<o<<endl;
				break;
			}
		}
	}
//	for(int v=1;v<=100;v++){
//		cout<<d[v];
//	}
	return 0;
}
