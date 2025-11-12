#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
int a[20];
int p[20];
int ans = 0;
//10pts
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s= " " + s;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int c = 1;
	for(int i = 1;i <= n;i ++){
		int tmp = 1;
		while(a[i + 1] == a[i]) tmp ++, i ++;
		c *= tmp;
	}
	for(int i = 1;i <= n;i ++) p[i] = i;
	int cnt;
	do{
		cnt = 0;
		int f = 0;
		for(int i = 1;i <= n;i ++){
			if(cnt < a[i] && s[i] == '1'){
				f ++;
			}else cnt ++;
		}
		if(f >= m){
			ans ++;
		}
	}while(next_permutation(a + 1, a + 1 + n));
	cout << ans * c;
	return 0;
}
