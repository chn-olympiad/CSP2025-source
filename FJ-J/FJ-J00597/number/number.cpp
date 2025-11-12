#include <bits/stdc++.h>
using namespace std;
int a[10000001];
int main (){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	string s;
	cin >> s;
	long long len = s.length();
	long long cnt = 0;
	long long flag = 0;
	for (long long i = 0; i < len; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			cnt ++;
			a[cnt] = s[i] - '0';
		}
	}
	sort (a + 1, a+cnt+1);
	for (long long i = cnt; i >= 1; i--){
		if (a[i] != 0 || flag == 1){
			printf ("%d", a[i]);
			flag = 1;
		}
		//cout << a[i] << " ";
	}
	if (flag == 0){
		cout << 0;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
