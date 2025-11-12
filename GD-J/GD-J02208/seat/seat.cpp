#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 110;
int n , m , x = 1 , y = 1 , r;
bool tmp = 1;
int s[MAXN];
bool cmp(int pre , int nxt){return pre > nxt;}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++){
		cin >> s[i];
	}
	r = s[1];
	sort(s + 1 , s + n * m + 1 , cmp);
	for(int i = 1 ; i <= n * m ; i++){
		if(s[i] == r) break;
		if(tmp == 1 && y == n){
			x++; tmp = 0;
		}
		else if(tmp == 0 && y == 1){
			x++; tmp = 1;
		}
		else if(tmp) y++;
		else y--;
	}
	cout << x << ' ' << y;
	return 0;
}
