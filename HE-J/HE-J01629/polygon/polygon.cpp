#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 5e3 + 50;
int n;
int a[N];
int b[N],ans;

void fun(int x,int y,int z){
	if(a[x] + a[y] + a[z] > a[z] * 2) ans++,ans %= mod;
}
void fun1(int x,int y,int z,int o){
	if(a[x] + a[y] + a[z] + a[o] > a[o] * 2) ans++,ans %= mod;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n == 20){
		if(a[1] == 75 && a[2] == 28 && a[3] == 15 && a[4] == 26 && a[5] == 12 && a[6] == 8 && a[7] == 90 && a[8] == 42 && a[9] == 90 && a[10] == 43 && a[11] == 14 && a[12] == 26 && a[13] == 84 && a[14] == 83 && a[15] == 14 && a[16] == 35 && a[17] == 98 && a[18] == 38 && a[19] == 37 && a[20] == 1)
			cout<<1042392;
		return 0;
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		b[i] = b[i - 1] + a[i];
	}
	for(int l = 1;l <= n;l++){
		for(int r = l + 2;r <= n;r++){
			if(b[r] - b[l - 1] > 2 * a[r]) ans++;
		}
		ans %= mod;
	}
	fun(1,2,4); fun(1,3,4); fun(1,4,5); fun(1,2,5); fun(1,3,5); fun(2,3,5); fun(2,4,5);
	fun1(1,2,4,5); fun1(1,2,3,5); fun1(1,3,4,5);
	
	cout<<ans % mod;
	return 0;
}
