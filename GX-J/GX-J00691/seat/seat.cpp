#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans;
int a[110];
int b[110][110];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) {
		cin>>a[i];
	}
	cnt=a[0];
	ans=n*m-1;
	sort(a,a+n*m);
	for(int i=1;i<=m;i++) {
		if(i%2!=0) {
			for(int j=1;j<=n;j++) {
				b[i][j]=a[ans];
				if(a[ans]==cnt) {
					cout<<i<<" "<<j;
					return 0;
				}
				ans--;
			}
		} else {
			for(int j=n;j>=1;j--) {
				b[i][j]=a[ans];
				if(a[ans]==cnt) {
					cout<<i<<" "<<j;
					return 0;
				}
				ans--;
			}
		}
	}
	return 0;
}
