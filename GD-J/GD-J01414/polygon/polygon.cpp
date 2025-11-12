#include<bits/stdc++.h>
#define debug 0
#define int long long
const int mod = 998244353;
//debug 1 -> start debug
using namespace std;
int n,a[5005],inv[5005],ans;
int qpow(int a,int b){
	int ans = 1;
	while(b){
		//ans = ans * ans % mod;
		if(b & 1)ans = ans * a % mod;
		b >>= 1;a = a * a % mod;
	}
	return ans % mod;
}
void solve1(){
	inv[0] = inv[1] = 1;
	//cout << qpow(2,10);
	for(int i = 2;i<= n;i++){
		inv[i] = inv[i - 1] * i % mod;
		//cout << inv[i] << " ";
	}
	for(int i = 3;i<= n;i++){
		ans += ((inv[n] * qpow(inv[i],mod - 2) % mod) * qpow(inv[n - i],mod - 2)) % mod;
		ans = ans % mod;
	}
	cout << ans;
}
int nmax,nsum,used;
bool vis[5005];
void dfs(int x,int where){
	if(x == n && used >= 3){
		ans++;
		return;
	}
	vis[where] = 1;
	for(int i = 1;i<= n;i++){
		if(vis[i])continue;
		int lmax = nmax,lsum = nsum;
		nmax = max(nmax,a[i]);
		nsum += a[i];used += 1;
		if(nmax * 2 >= nsum && used >= 3)return;
		dfs(x + 1,i);
		nmax = lmax;nsum = lsum;used -= 1;
		dfs(x + 1,i);
	}
	vis[where] = 0;
}
void the_true_main(){
	//¿¼ÂÇÄÃ15-20µÄ·Ö
	bool sv = 0;
	cin >> n;
	for(int i = 1;i<= n;i++){
		cin >> a[i];
		if(a[i] > 1)sv = 1;
	}
	if(!sv)solve1();
	else{
		for(int i = 1;i<= n;i++){
			nmax = nsum = used = 0;
			dfs(1,i);
		}
		cout << ans;
	}
}
signed main(){
	#if debug == 1
	cout << "start debug\n";
	#else
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	#endif
	the_true_main();
	#if debug == 0
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
} 
