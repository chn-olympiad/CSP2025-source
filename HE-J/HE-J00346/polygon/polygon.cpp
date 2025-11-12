#include<bits/stdc++.h>

using namespace std;
const int N = 6000,M = 998244353;
long long n, a[N] ,ans, b[N], k[N];
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	k[1] = 1;
	k[0] = 1;
	for(long long i = 2;i <= 5000;i ++){
		k[i] = k[i - 1] * i % M;
	}
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n,cmp);
	for(int i = 1;i <= n;i ++){
		b[i] = b[i - 1] + a[i];
	}
	for(int i = 1;i <= n - 2;i ++){
		long long l = i + 1, r = n, mid, x = 2 * a[i];
		while(l + 1 != r){
			mid = l + r >> 1;
			if(b[mid] - b[i - 1] <= x){
				l = mid;
			}else{
				r = mid;
			}
		}
		if(b[r] > x){
			long long h = n - r + 1, p = 1;
			for(int j = 1;j <= h;j ++){
				p = p * (k[h] / (k[h - j] * k[j])) % M;  
			}
			ans = (ans + p) % M;
		}
	}
	cout << ans;
	return 0;
}
