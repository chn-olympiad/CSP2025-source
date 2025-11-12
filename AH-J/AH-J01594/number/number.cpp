#include <bits/stdc++.h>
using namespace std;

int cnt, a[1000005];

bool cmp(int A, int B){
	return A > B;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i ++){
		if(s[i] >= '0' && s[i] <= '9')
			a[++ cnt] = s[i] - '0';
	}
	sort(a + 1, a + 1 + cnt, cmp);
	for(int i = 1; i <= cnt; i ++)
		printf("%d", a[i]);
	return 0;
}
