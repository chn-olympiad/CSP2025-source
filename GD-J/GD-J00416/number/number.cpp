#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int a[N];
char s[N];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int id = 0;
	scanf("%s", &s);
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		if(s[i] >= '0' &&  s[i] <= '9'){
			id++;
			a[id] = s[i] - '0';
		}
	}
	sort(a + 1, a + id + 1);
	for(int i = id; i >= 1; i--) cout << a[i];
	return 0;
}
