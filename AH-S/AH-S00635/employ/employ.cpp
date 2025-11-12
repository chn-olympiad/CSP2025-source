#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,ans,a[505],sum,x,kc,r;
char c[505];
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> c;
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << endl;
	for(i=1;i<=n;i++){
		if(a[i] != 0)r++;
	}
	flag = 1;
	for(i=0;i<n;i++){
		if(c[i] == '0')flag = 0;
	}
	if(flag){
		for(i=m;i<=r;i++){
			sum = 1;
			for(j=r;j>=r-i+1;j--){
				sum *= j;
				sum /= r-j+1;
				if(sum >= 1e17)sum %= 998244353;
			}
			ans += sum;
		}
		ans %= 998244353;
		cout << ans;
	}
	return 0;
}



