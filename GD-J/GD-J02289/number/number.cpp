#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string x;
int a[N], cnt = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> x;
	for(int i = 0; i < x.size(); i++)
		if(x[i] >= '0' && x[i] <= '9') a[++cnt] = x[i] - '0';
	sort(a + 1, a + cnt + 1);
	for(int i = cnt; i >= 1; i--) printf("%d", a[i]);
	return 0;
} 
