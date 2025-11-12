#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 10;
const int mod = 998244353;
int n,a[N];
int sum[N],f[N],ans;
bool flag;
int init(int n,int m){
	int num1 = 1;
	for(int i = n - m + 1;i <= n;i++)
		num1 *= i;
	int num2 = 1;
	for(int i = 1;i <= m;i++)
		num2 *= i;
	return num1 / num2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1)
			flag = true;
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	if(n <= 2){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(sum[3] > a[3] * 2)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if(!flag){
		for(int i = 3;i <= n;i++)//3~n±ßÐÎ 
			ans += init(n,i);
		cout << ans << endl;
		return 0;
	}
	for(int l = 1;l <= n;l++){
		int L = sum[l - 1];
		for(int len = 3;len + l - 1 <= n;len++){
			int r = l + len - 1;
			int R = sum[r];
			int num = R - L;
			if(num > a[r] * 2){
				cout << l << " " << r << endl;
				for(int i = 3;i <= len;i++)
					f[r] += init(r - 1,i);
			}
			
		}
	}
	cout << ans % mod << endl;
	return 0;
}
