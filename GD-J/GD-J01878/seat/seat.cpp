#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
int a[N];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ;i <= n * m;i ++) cin >> a[i];
	int r = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 1, y = 1, tmp = 1, cnt = 1;
	while(1){
		if(a[cnt] == r){
			cout << y << " " << x;
			break;
		}
		if(tmp == 1){
			if(x < n){
				x ++;
				cnt ++;
			}else{
				y ++;
				tmp = 0;
				cnt ++;
			}
		}else{
			if(x > 1){
				x --;
				cnt ++;
			}else{
				y ++;
				tmp = 1;
				cnt ++;
			}
		}
	}
	return 0;
}
