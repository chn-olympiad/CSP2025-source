#include<bits/stdc++.h>
using namespace std;
int n,m,c[509],st[509];
char s[509];
const int mod = 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf(" %s",s + 1);
	st[0] = 1;
	for(int i = 1; i <= n; i ++){
		scanf("%d",&c[i]);
		st[i] = 1ll * st[i - 1] * i % mod;
	}
	sort(c + 1,c + n + 1);
	if(m == n){
		if(c[1] == 0)
			return puts("0") && 0;
		for(int i = 1; i <= n; i ++){
			if(s[i] == '0')
				return puts("0") && 0;
		}
		printf("%d\n",st[n]);
	}
}
