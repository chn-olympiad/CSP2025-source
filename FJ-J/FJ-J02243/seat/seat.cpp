#include<bits/stdc++.h>
using namespace std;

int n, m, u, g0, s0, g[120], x = 1, y = 1;

bool cmd(int a, int b){
	if(a > b) return true;
	else return false;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >>n >>m;
	u = n*m;
	for(int i = 1; i <= u; i ++) cin >>g[i];
	g0 = g[1];
	sort(g+1, g+u+1, cmd);
	//for(int i = 1; i <= u; i ++) cout <<g[i];
	for(int i = 1; i <= u; i ++) if(g[i] == g0) s0 = i;
	while(x <= m){ //第x列，第y行 
		if(x%2 == 1){
			while(y <= n){
				s0 --;
				if(s0 == 0){
					cout <<x <<" " <<y;
					return 0;
				}
				y ++;
			}
			y --;
		}else{
			while(y >= 1){
				s0 --;
				if(s0 == 0){
					cout <<x <<" " <<y;
					return 0;
				}
				y --;
			}
			y ++;
		}
		x ++;
	}
	
	return 0;
}
/*
2 2
99 100 97 98
*/
