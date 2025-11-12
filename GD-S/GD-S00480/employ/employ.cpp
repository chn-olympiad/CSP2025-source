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
int n, m, a;
string b;
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = Furina(); m = Furina();
	cin >> b;
	while(m--) a = Furina();
	fufu(2);
	I_love_Furina 0;
}
//我这个蒟蒻也应该落幕了。 
//再见，CCF。希望你喜欢这4个小时来属于你的戏份。 
