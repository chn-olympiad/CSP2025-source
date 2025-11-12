# include<bits/stdc++.h>
# define N 1000005
using namespace std;
int len;
char a[N];
map<char, int> q;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);
	cin >> (a + 1);
	len = strlen(a + 1);
	for(int i = 1; i <= len; i ++)
		q[a[i]] ++;
	for(char i = '9'; i >= '0'; i --)
		for(int j = q[i]; j >= 1; j --)
			cout << i;
	return 0;
}