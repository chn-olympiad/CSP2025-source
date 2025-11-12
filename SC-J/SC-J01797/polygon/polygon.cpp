#include <bits/stdc++.h>
using namespace std;

int a[5050], b[5050];

bool cmp(int x, int y){
	return x > y;
}

bool used[5050];

int sum, cnt, n;

void go(int ch, int op, int final, int last){
	if (op == final + 1){
		if (sum > a[ch] * 2){
			cnt++; 
		}
		cnt %= 998244353;
		return;
	}
	for (int i = last + 1; i <= n; i++){
		if (!used[i]){
			used[i] = 1;
			if (op != 1){
				sum += a[i];
				go(ch,op + 1,final,i);
				sum -= a[i];
			}
			else{
				sum += a[i];
				go(i,op + 1,final,i);
				sum -= a[i];
			}
			used[i] = 0;
		}
		
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 3; i <= n; i++){
		go(0,1,i,0);
	}
	cout << cnt << "\n";
	return 0;
}