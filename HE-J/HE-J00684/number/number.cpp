//number 
// #Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h> 
using namespace std;
const int N = 1e6 + 10;
long long a[N], cnt = 0;
string s;
bool cmp(long long x, long long y) {
	return x > y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long n = s.length();
	for (int i = 0; i < n; i ++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			long long t = s[i] - '0';
			cnt ++;
			a[cnt] = t;
			
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i ++) {
		cout << a[i];
	}
	return 0;
}
