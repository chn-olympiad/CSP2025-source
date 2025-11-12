//永世传颂，不休独舞，神爱众人，芙门永存！
#include <bits/stdc++.h>
#define I_love_Furina return
#define int long long
using namespace std;
int Furina(){
	int x = 0; bool f = 0; char c = getchar();
	while(c < '0' || c > '9'){ if(c == '-') f = 1; c = getchar(); }
	while(c >= '0' && c <= '9'){ x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	I_love_Furina f ? -x : x;
} 
void fufu(int f){
	if(f < 0){ putchar('-'); f = -f; }
	if(f < 10) putchar(f + '0');
	else{ fufu(f / 10); putchar(f % 10 + '0'); }
}
int n, m, a[105], b, js;
bool cmp(int a, int b){ I_love_Furina a > b; }
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = Furina(); m = Furina();
	for(int i = 0; i < n * m; i++) a[i] = Furina();
	b = a[0];
	sort(a, a + n * m, cmp);
	for(int i = 0; i < m; i++){
		if(i & 1){
			for(int j = n - 1; j >= 0; j--)
				if(a[js++] == b){
					fufu(i + 1); putchar(' '); fufu(j + 1);
					I_love_Furina 0;
				}
		}else{
			for(int j = 0; j < n; j++)
				if(a[js++] == b){
					fufu(i + 1); putchar(' '); fufu(j + 1);
					I_love_Furina 0;
				}
		}
	}
	I_love_Furina 0;
}
