#include <bits/stdc++.h>
using namespace std;

int st[10][10];
int n,m;
int cj[100];
int r;

bool cmp(int a,int b) {
	return a > b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n*m; i++) {
		scanf("%d",&cj[i]);
	}
	r=cj[1];
	sort(cj+1,cj+1+n*m,cmp);
	//²âÊÔ
	/*for(int i=1; i<=n*m; i++) {
		cout << cj[i] << ' ';
	}
	cout << endl;*/
	//²âÊÔ
	for(int i=1,k=1; i<=m; i++) {
		if(i%2) {
			for(int j=1; j<=n; j++,k++) {
				st[i][j]=cj[k];
			}
		} else {
			for(int j=n; j>=1; j--,k++) {
				st[i][j]=cj[k];
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(st[i][j] == r) {
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}

