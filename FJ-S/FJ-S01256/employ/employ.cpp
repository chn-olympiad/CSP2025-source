#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod = 998244353;
const int N = 5e2 + 5;
int n,m;
char s[N];
int a[N];
void Add(int &x,int y){
	if ((x += y) >= Mod) x -= Mod;
}
namespace subtask1{
	int f[20][1 << 18];
	void main(){
		f[0][0] = 1;
		for (int i = 0;i < n;++i){
			for (int j = 0;j < (1 << n);++j){
				if (f[i][j] == 0) continue;
				//cout << i << " " << j << " " << f[i][j] << endl; 
				int p = __builtin_popcount(j);
				for (int k = 0;k < n;++k){
					if ((j >> k & 1) == 0){
						if (a[k] > i && s[p] == '1') Add(f[i][j | (1 << k)],f[i][j]);
						else Add(f[i + 1][j | (1 << k)],f[i][j]);
					}
				}
			}
		} int res = 0;
		for (int i = n - m;i >= 0;--i)
		    Add(res,f[i][(1 << n) - 1]);
		printf("%d\n",res);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	
	for (int i = 0;i < n;++i) scanf("%d",&a[i]);
	if (n <= 18) subtask1 :: main();
	
	return 0;
}
