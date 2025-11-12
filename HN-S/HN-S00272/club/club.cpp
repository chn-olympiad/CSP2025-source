#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int z, n, a[N][5], b[N][5], t[5];
struct number{
	int my, cb, id, b1, b2;
}c[N];
bool cmp1(number x, number y){	
	if(x.cb == 1 && y.cb != 1) return true;
	if(x.cb == 1 && y.cb == 1 && x.b1 > y.b1) return true;
	return false;
}
bool cmp2(number x, number y){	
	if(x.cb == 2 && y.cb != 2) return true;
	if(x.cb == 2 && y.cb == 2 && x.b1 > y.b1) return true;
	return false;
}
bool cmp3(number x, number y){	
	if(x.cb == 3 && y.cb != 3) return true;
	if(x.cb == 3 && y.cb == 3 && x.b1 > y.b1) return true;
	return false;
}
int main(){
	freopen("club.in","r", stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &z);
	while(z --){
		memset(t, 0, sizeof(t));
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++){
			c[i].id = i;
			for(int j = 1; j <= 3; j ++){
				scanf("%d", &a[i][j]);
				if(a[i][j] > c[i].my){
					c[i].my = a[i][j];
					c[i].cb = j;
				}
			}
			t[c[i].cb] ++;
			int x[3] = {a[i][1], a[i][2], a[i][3]};
			sort(x, x + 3);
			c[i].b1 = x[2] - x[1], c[i].b2 = x[1] - x[0];
		}
		if(t[1] > (n / 2)){
			sort(c + 1, c + 1 + n, cmp1);
			for(int i = n/2 + 1; i <= t[1]; i ++){
				int x;
				c[i].my -= c[i].b1;
				c[i].b1 = c[i].b2;
				for(int j = 1; j <= 3; j ++){
					if(a[c[i].id][j] == c[i].my){
						c[i].cb = j;
						t[j] ++;
						break;
					}
				}
			}
			t[1] = n / 2;
		}
		if(t[2] > (n / 2)){
			sort(c + 1, c + 1 + n, cmp2);
			for(int i = n/2 + 1; i <= t[2]; i ++){			
				int x;
				c[i].my -= c[i].b1;
				//cout<<c[i].my<<" "<<c[i].cb<<" "<<c[i].b1<<endl;
				for(int j = 1; j <= 3; j ++){
					if(a[c[i].id][j] == c[i].my){
						c[i].cb = j;
						t[j] ++;
						break;
					}
				}
			}
			t[2] = n / 2;
		}
		if(t[3] > (n / 2)){
			sort(c + 1, c + 1 + n, cmp3);
			/*for(int i = 1; i <= n; i ++){
				cout<<c[i].my<<" "<<c[i].cb<<endl;
			}*/
			for(int i = n/2 + 1; i <= t[3]; i ++){
				int x;
				c[i].my -= c[i].b1;
				for(int j = 1; j <= 3; j ++){
					if(a[c[i].id][j] == c[i].my){
						c[i].cb = j;
						t[j] ++;
						break;
					}
				}
			}
			t[3] = n / 2;
		}
		if(t[1] > (n / 2)){
			sort(c + 1, c + 1 + n, cmp1);
			for(int i = n/2 + 1; i <= t[1]; i ++){
				int x;
				c[i].my -= c[i].b1;
				c[i].b1 = c[i].b2;
				for(int j = 1; j <= 3; j ++){
					if(a[c[i].id][j] == c[i].my){
						c[i].cb = j;
						t[j] ++;
						break;
					}
				}
			}
			t[1] = n / 2;
		}
		if(t[2] > (n / 2)){
			sort(c + 1, c + 1 + n, cmp2);
			for(int i = n/2 + 1; i <= t[2]; i ++){
				int x;
				c[i].my -= c[i].b1;
				for(int j = 1; j <= 3; j ++){
					if(a[c[i].id][j] == c[i].my){
						c[i].cb = j;
						t[j] ++;
						break;
					}
				}
			}
			t[2] = n / 2;
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			//cout<<c[i].my<<" "<<c[i].cb<<endl;
			ans += c[i].my;
		}
		cout<<ans<<endl;
		for(int i = 1; i <= n; i ++){
			c[i].cb = 0, c[i].my = 0;
			c[i].id = 0, c[i].b1 = 0, c[i].b2 = 0;
		}
	}
	return 0;
/*3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
*/
/* 1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
 */
 //Ren5Jie4Di4Ling5%
}
