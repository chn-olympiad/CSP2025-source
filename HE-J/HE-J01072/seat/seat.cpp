#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1e6+5;
int a[N],ans=0;
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int p=a[1];
//	for(int i=1;i<=n*m; i++) {
//		int x=a[i];
//		if(a[i]<a[i+1]) {
//			a[i]=a[i+1];
//			a[i+1]=x;
//		}
//	}
sort(a+1,a+1+(n*m));
	for(int i=1; i<=n*m; i++) {
		if(p==a[i]) {
			p=n*m-i+1;
		}
	}
	if(p%m==0) {
		cout<<m<<" "<<n;
		return 0;
	}
	for(int i=1; i<=n*m; i++) {
		if(p>=m) {
			p-=m;
			ans++;
		}
		if(ans>0&&p!=0&&p<m) {
			ans+=1;
			break;
		}

	}
	if(ans%2==0) {
		cout<<ans<<" "<<m-p+1;
	} else if(ans%2==1&&ans!=1) cout<<ans<<" "<<p;
	else if(ans==1)cout<<ans<<" "<<m-p;
	return 0;
}

