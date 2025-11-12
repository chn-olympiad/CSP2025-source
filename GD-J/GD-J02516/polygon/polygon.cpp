#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[50005];
int ans,sum,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0;i<n;i++) cin >> a[i];
	//for (int i = 0;i<n;i++) cout << a[i] << " ";
	//cout << endl; 
	for (int i = 1;i < (1<<n);i++){
		sum = 0;
		m = -1;
		cnt = 0;
		for (int j = 0;j < n;j++){
			if ((i&(1<<j))==(1<<j)){
				sum += a[j];
				m = max(m,a[j]);
				cnt++;
			}
		}
		if (cnt>=3&&sum>2*m) ans++;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
