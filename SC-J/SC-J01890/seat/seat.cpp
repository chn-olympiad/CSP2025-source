#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int m, n, ans;

struct node{
	int x, ids;
}a[N];

void bubble_sort(int x, node a[]){
	for (int i = 1;i < n;i++){
		bool flag = 1;
		for (int j = 1;j <= n - i;j++){
			if (a[j].x < a[j + 1].x){
				swap(a[j], a[j + 1]);
				flag = 0;
			}
		}
		if (flag == 0) return;
	}
	return;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1;i <= n * m;++i){
		cin >> a[i].x;
		a[i].ids = i;
	}
	bubble_sort(n * m, a);
	int o = 1, p = 1;
	for (;p <= m;){
		for (;o <= n;++o){
			ans++;
			if (a[ans].ids == 1){
				cout << o  << " " << p;
				return 0;
			}
		}
		p++;
		for (;o >= 1;--o){
			ans++;
			if (a[ans].ids == 1){
				cout << o  << " " << p;
				return 0;
			}
		}
		p++;
	}
	return 0;
}

/*

不可以，总司令！（骗分）

Dear CCF:

   I love you, because I want to akioi!

love,
__Little_Henry__ (luogu id)

*/