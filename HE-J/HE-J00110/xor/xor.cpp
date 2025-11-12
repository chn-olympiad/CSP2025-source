#include <bits/stdc++.h>
using namespace std;
int n , k;
int a[500005];
string b[500005];
int f[500005];
string zrjz(int x){
	if (x == 0) return "0";
	string s1 = "";
	string s2 = "";
	while (x > 0){
		if (x % 2 == 0)
			s1 += "0";
		else s1 += "1";
		x /= 2;
	}
	for (int i = s1.length() - 1 ; i >= 0 ; i--) s2 += s1[i];
	return s2;
}
string zhuan(string x , string y){
	string s1 = "";
	int ans;
	if (x.length() > y.length()) ans = 2;
	else if (x.length() < y.length()) ans = 1;
	else ans = 0;
	for (int i = 0 ; i < max(x.length() , y.length()) ; i++){
		if (ans == 1 && y.length() - x.length() - 1 >= i)
			s1 += y[i];
		else if (ans == 2 && y.length() - 1 >= i)
			s1 += x[i];
		else if (ans == 1){
			if (x[i - (y.length() - x.length())] == '1' && y[i] == '0') s1 += "1";
			else if (x[i - (y.length() - x.length())] == '0' && y[i] == '1') s1 += "1";
			else s1 += "0";
		}
		else if (ans == 2){
			if (x[i] == '1' && y[i - (x.length() - y.length())] == '0') s1 += "1";
			else if (x[i] == '0' && y[i - (x.length() - y.length())] == '1') s1 += "1";
			else s1 += "0";
		}
		else {
			if (x[i] == '1' && y[i] == '0') s1 += "1";
			else if (x[i] == '0' && y[i] == '1') s1 += "1";
			else s1 += "0";
		}
	}
	return s1;
}
int ss(string x){
	int ans = 0;
	for (int i = 0 ; i < x.length() ; i++){
		if (x[i] == '1')
			ans += pow(2 , x.length() - i - 1);
		else continue;
	}
	return ans;
}
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	for (int i = 1 ; i <= n ; i++) b[i] = zrjz(a[i]);
	f[0] = 0;
	int ans = 0;
	for (int i = 1 ; i <= n ; i++){
		if (a[i] == k){
			ans = 0;
			f[i] = f[i - 1] + 1;
		}
		else if (ss(zhuan(b[i] , b[i - 1])) == k){
			ans = 0;
			f[i] = f[i - 1] + 1;
		}
		else if (ss(zhuan(b[i] , zrjz(ans))) == k){
			ans = 0;
			f[i] = f[i - 1] + 1;
		}
		else {
			ans = ss(zhuan(b[i] , zrjz(ans)));
			f[i] = f[i - 1];
		}
	}
	cout << f[n];
	return 0;
}
