#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,x,ans,num,maxx;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out" , "w", stdout);
	cin >> n;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for (int i = 1;i<=(1<<n);i++){
		x= i;
		ans = 0;
		num = 0;
		maxx=INT_MIN;
		while(x>0){
			ans++;
			if (x&1==1){
				num+=a[ans];
				maxx = max(maxx,a[ans]);
			}
			x>>=1;
		}
		if (num>maxx*2) sum++;
	}
	cout << sum%998244353;
	return 0;
}
