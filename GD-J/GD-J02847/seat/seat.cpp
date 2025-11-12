#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int len = n * m;
    for(int i = 1; i <= len; i++) cin >> a[i];
    int tmp = a[1], pos;
    sort(a + 1, a + len + 1, cmp);
    for(int i = 1; i <= len; i++){
    	if(a[i] == tmp){
    		pos = i;
    		break;
		}
	}
	int c = pos / n + 1, r = pos % n;
	if(r == 0) c--;
	cout << c << ' ';
	if(c % 2 == 1){
		if(r == 0) cout << n;
		else cout << r;
	}else{
		if(r == 0) cout << 1;
		else cout << (n - r + 1);
	}
    return 0;
}
