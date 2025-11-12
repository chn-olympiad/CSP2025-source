#include <iostream>
#include <algorithm>
using namespace std;
struct stu{
	int val, pos;
}a[105];
int n, m, ans, len;
bool cmp(stu x, stu y){ return x.val > y.val; }
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.ans", "w", stdout);
	cin >> n >> m, len = n * m;
	for(int i = 1;i <= len;i++) cin >> a[i].val, a[i].pos = i;
	if(n == 1 && m == 1){
		cout << 1 << ' ' << 1 << endl;
		return 0;
	}
	sort(a + 1, a + len + 1, cmp);
	if(n == 1){
		for(int i = 1;i <= m;i++){
			if(a[i].pos == 1){
				cout << i << ' ' << 1 << endl;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		if(i % 2 == 0){
			for(int j = n;j >= 1;j--){
				if(a[i * j].pos == 1){
					cout << i << ' ' << j << endl;
					return 0;
				}
			}
		}else{
			for(int j = 1;j <= n;j++){
				if(a[i * j].pos == 1){
					cout << i << ' ' << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
