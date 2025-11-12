#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 3) + (s << 1) + ch - '0';ch = getchar();}
	return s * w;
}
int n,m,c[550],id[550],ans = 0;
char s[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read();m = read();
	scanf("%s",s + 1);
	for(int i = 1;i <= n;i++){
		c[i] = read();id[i] = i;
	}
	if(n <= 10){
		do{
			int abandon = 0,p = 0;
			for(int i = 1;i <= n;i++){
				if(abandon >= c[id[i]]){
					abandon++;
					continue;
				}
				if(s[i] == '0') abandon++;
				else p++;
			}
			if(p >= m) ans++;
		}while(next_permutation(id + 1,id + n + 1));
		cout << ans << "\n";
	}
	else{
		ans = 1;
		for(int i = 1;i <= n;i++)
			ans = ans * i % MOD;
		cout << ans << "\n";
	}
	return 0;
}

