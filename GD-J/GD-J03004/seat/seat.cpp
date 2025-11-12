#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[6000000];
bool cmp(int a,int b) {
	return a>b;
}
ll cnt;
ll ans[20+1][20+1];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	ll l=1,r=n;
	for(int i=1; i<=m; i++) {
		cnt++;
		if(i!=1){
			l+=n,r+=n;
		}
		if(cnt%2) {
			for(int j=l,k=1; j<=r,k<=n; j++,k++) {
				ans[k][i]=a[j];
			}
		}else{
			for(int j=r,k=1; j>=l,k<=n; j--,k++) {
				ans[k][i]=a[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==xr){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
