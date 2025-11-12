#include<bits/stdc++.h>
using namespace std;
int n,m,x[10005],mmap[105][105],sum,a;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=n*m;i++) {
		cin>>x[i];
	}
	a=x[1];
	sort(x+1,x+1+n*m);
	for(int i=1;i<=m;i++) {
		if(i%2==1) {
			for(int j=1;j<=n;j++) {
				mmap[j][i]=x[sum];
				sum--;
			}
		} else {
			for(int j=n;j>0;j--) {
				mmap[j][i]=x[sum];
				sum--;
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(mmap[i][j]==a) {
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

