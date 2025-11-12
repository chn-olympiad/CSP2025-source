#include <bits/stdc++.h>
using namespace std;

int n,m;
int s[105] = {};
int t[15][15] = {};

int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> s[i];
	}
	int rs = s[1];
	int cnt = 1;
	sort(s + 1,s + n * m,greater<int>());
	int j;
	for(j = 0;j <= m;){
		j++;
		for(int i = 1;i <= n;i++){
			t[j][i] = s[cnt++];
			if(t[j][i] == rs){
				cout << j << ' ' << i;
				return 0;
			}
		}
		j++;
		for(int i = n;i >= 1;i--){
			t[j][i] = s[cnt++];
			if(t[j][i] == rs){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
}
