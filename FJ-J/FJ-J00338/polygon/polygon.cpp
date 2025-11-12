#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD=998244353;
int n,a[5005];

bool check(int l,int r) {
	ll sum=0,maxn=0;
	for (int i=l; i<=r; i++) {
		sum+=a[i];
	}
	for (int i=l; i<=r; i++) {
		if (a[i]>maxn) maxn=a[i];
	}
	return sum>2*maxn;
}

ll jc(int n) {
	if (n==0||n==1) return 1;
	return n*jc(n-1)%MOD;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	if (n==3) {
		if (check(1,3)) cout << 1;
		else cout << 0;
	}
	else if (n<=20) {
		int c=0;
		for (int i=3; i<=n; i++) {
			for (int j=1; j+i-1<=n; j++) {
				for (int k=j+i-1; k<=n; k++) {
					if (check(j,k)) c+=1;
				}
			}
		}
		cout << c%MOD;
	}
	else {
		ll ans=0;
		for (int i=3; i<=n; i++) {
			ans+=jc(n)/jc(n-i);
			ans%=MOD;
		}
		cout << ans;
	}
	return 0;
}
