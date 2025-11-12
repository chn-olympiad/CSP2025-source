//永世传颂，不休独舞，神爱众人，芙门永存！
#include <bits/stdc++.h>
#define I_love_Furina return
#define int long long
using namespace std;
const int N = 1e5 + 5;
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
int n, m, a[N], sum, ans;
bool f;
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = Furina(); m = Furina();
	for(int i = 1; i <= n; i++) a[i] = Furina();
	for(int i = 1; i <= n; i += (f ? 0 : 1)){
		sum = a[i]; f = 0;
		for(int j = i + 1; j <= n; j++){
			if(sum == m){
				ans++; i = j; f = 1; sum = -1;
				break;
			}
			sum = sum ^ a[j];
		}
		if(sum == m){ sum = -1; ans++; break; }
	}
	if(sum == m) ans++;
	fufu(ans);
	I_love_Furina 0;
}
