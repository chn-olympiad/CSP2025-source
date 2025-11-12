#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,k,ans=1;
int xo(int a, int b){
	return (a^b);
}

struct inter{
	int le,ri;
}a[N];
bool cmp(inter c, inter d){
	return c.ri < d.ri;
}
int dp[N][N];
int arr[N];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	int ind = 0;
	for (int l = 1;l <= n;l++){
		for (int r = l; r <= n;r++){
			if (l == r){
				dp[l][r] = arr[l];
			}
			else{
				dp[l][r] = xo(dp[l][r-1],arr[r]);
			}
			if (dp[l][r] == k){
				a[ind].le = l;
				a[ind].ri = r;
				ind++; 
			}
		}
	}
	sort(a,a+ind,cmp);
	int r = a[0].ri;
//	cout << r << endl;
	for (int i= 0;i < ind;i++){
//		cout << "l" << a[i].le << endl;
//		cout << r << endl;
		if (a[i].le > r){
			ans++;
			r = a[i].ri;
		}
	}
	cout << ans << endl;
	return 0;
}
