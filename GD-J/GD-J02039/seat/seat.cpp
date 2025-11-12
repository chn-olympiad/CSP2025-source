#include <iostream>
#include <algorithm>
using namespace std;
int xin[10010];
bool bj(int X,int Y){
	return X > Y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++)cin >> xin[i];
	int A = xin[1];
	sort(xin + 1,xin + 1 + n * m,bj);
	int x = 1,y = 1;
	int num = 1;
	bool op = 1;
	while(1){
		if(xin[num] == A){
			cout << x << ' ' << y;
			return 0;
		}
		if(op == 1 && y == n){
			op = 0;
			x ++;
		}else if(op == 0 && y == 1){
			op = 1;
			x ++;
		}else {
			if(op)y ++;
			else y --;
		}
		num ++;
	}
	return 0;
}
