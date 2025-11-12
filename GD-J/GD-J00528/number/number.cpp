//永世传颂，不休独舞，神爱众人，芙门永存！
#include <bits/stdc++.h>
#define I_love_Furina return
#define int long long
using namespace std;
void fufu(int f){
	if(f < 0){ putchar('-'); f = -f; }
	if(f < 10) putchar(f + '0');
	else{ fufu(f / 10); putchar(f % 10 + '0'); }
}
string a;
int b[15];
bool f, f2;
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for(int i = 0; i < a.size(); i++)
		if(a[i] >= '0' && a[i] <= '9') b[a[i] - '0']++;
	for(int i = 9; i >= 0; i--){
		if(!i && !f2){ fufu(0); I_love_Furina 0; }
		for(int j = 0; j < b[i]; j++){
			fufu(i); f = 1;
			if(i > 0) f2 = 1;
		}
	}
	if(!f) fufu(0);
	I_love_Furina 0;
}
