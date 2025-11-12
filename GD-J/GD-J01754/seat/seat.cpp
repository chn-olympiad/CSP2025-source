#include<bits/stdc++.h>
using namespace std;
const int N = 11,M = 11;
int n,m;
int x = 0,y = 0;
int s[N][M];
int input_input[121];
bool cmp(int a,int b){
	return a >= b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n * m;i ++) cin >> input_input[i];
	int r = input_input[0];
	int su = 1;
	sort(input_input,input_input+(n * m),cmp);
	for (int i = 0;i < n * m;i ++){ 
		s[x][y] = input_input[i];
		if (s[x][y] == r) {
			cout << y + 1 << ' ' << x + 1;
			break;
		}
		x += su;
		if (x == n or x == -1) {
			y ++;
			if (su == 1) x = n - 1;
			else x = 0;
			su *= -1;
		} 
	}
	return 0;
}
