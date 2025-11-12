#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int n, m;
char str[20];
int c[20];
int f[20][1000002];

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> str+1;
	for(int i=1;i<=n;i++) cin >> c[i];
	f[0][0] = 1;
	for(int i=0;i<(1<<n);i++){
		int s = 0;
		for(int j=1;j<=n;j++){
			if((i >> (j-1)) & 1) s++;
		}
		for(int j=0;j<=s;j++){
			for(int k=1;k<=n;k++){
				if(((i >> (k-1)) & 1) ^ 1){
					if(s-j < c[k] && str[s+1] == '1') {
						f[j+1][i ^ (1 << (k-1))] = (f[j+1][i ^ (1 << (k-1))] + f[j][i]) % mod;
					}
					else {
						f[j][i ^ (1 << (k-1))] = (f[j][i ^ (1 << (k-1))] + f[j][i]) % mod;
					}
				}
			}
		}
	}
	int Ans = 0;
	for(int i=m;i<=n;i++) Ans = (Ans + f[i][(1<<n)-1]) % mod;
	cout << Ans;
	
	return 0;
}

/*

3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
