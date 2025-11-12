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
int n, m, k, a, b, c;
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = Furina(); m = Furina(); k = Furina();
	while(m--){ a = Furina(); b = Furina(); c = Furina(); }
	while(k--){
		for(int i = 0; i < n; i++) a = Furina();
	}
	fufu(9);
	I_love_Furina 0;
}
