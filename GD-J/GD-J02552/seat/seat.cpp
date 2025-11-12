#include <bits/stdc++.h>
using namespace std;
struct node{
	int num, id;
}s[105];
int n, m;
int main(){
	freopen("seat.in", " r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) {
		cin >> s[i].num;
		s[i].id = i;
	}
	sort(s+1, s+n*m+1, [](node l, node r){
		return l.num > r.num;
	});
	if(s[1].id == 1){
		cout << "1 1";
		return 0;
	}else if(s[n*m].id == 1) {
		if(m % 2 == 0){
			cout << "1 " << m;
		}else cout << n << " " << m;
		return 0;
	}
	int now = 1;
	for(int i = 1; i <= m; i ++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				if(s[now].id != 1) now++;
				else {
					cout << i << " " << j;
					return 0;
				}
			}
		}else {
			for(int j = n; j >= 1; j--){
				if(s[now].id != 1) now++;
				else {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}

