#include <bits/stdc++.h>
using namespace std;
long long n,m,a[505],t=1,c[505],ans=0,cnt=0;
string b;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> b;
	for (int i=0;i<=n-1;i++){
		cin >> a[i];
	}
	long long q=1;
	for (int i=n;i>=1;i--){
		q=q*i;
	}
	for (int i=0;i<=n-1;i++){
		for (int j=m-1;j<=q;j++){
			ans+=n-j;
		}
		n--;
	}
	cout << ans%998244353;
	return 0;
}
