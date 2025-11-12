#include<bits/stdc++.h>
using namespace std;
struct st {
	int sc;
};
bool cmp(st x,st y) {
	return x.sc>y.sc;
}
int main() {
	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	int n,m;
	cin>>n>>m;
	st t[n*m+1];
	for(int i=1; i<=n*m; i++) {
		cin>>t[i].sc;
	}
	int r1=t[1].sc;
	sort(t+1,t+n*m+1,cmp);
	int a[n+1][m+1]= {0};
	int p=1;
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				a[j][i]=t[p].sc;

				if(t[p].sc==r1) {
					cout<<i<<" "<<j;
					return 0;
				}
				p++;
			}
		} else if(i%2==0) {
			for(int j=n; j>0; j--) {
				a[j][i]=t[p].sc;

				if(t[p].sc==r1) {
					cout<<i<<" "<<m-j;
					return 0;
				}
				p++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
