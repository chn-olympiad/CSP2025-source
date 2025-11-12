#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 998244353;
int n,m,k,res=0;
int C[505][505],a[1005];
string s1;
int main(){
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 
//	freopen("C:\\Users\\Administrator\\Desktop\\ÌâÄ¿\\employ\\employ3.in","r",stdin); 
//	freopen("out.txt","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s1;
	for (int i = 1; i <= n;i++){
//		if (a[i] >= res) k++;
		cin >> a[i];
		if (a[i] != 0) k++;
		else res++;
		
	}
	
//	cout << k << ' ' << res << '\n';
	for (int i = 0; i <= n;i++){
		C[i][0]=1;
		for (int j = 1; j <= i;j++){
			C[i][j] = (C[i-1][j-1] % MOD + C[i-1][j] % MOD) % MOD;
		} 
	}
	
	cout << C[k][m];
	
	
	return 0;
}

