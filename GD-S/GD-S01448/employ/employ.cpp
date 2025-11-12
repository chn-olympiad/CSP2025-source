#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pint pair<int,int>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define fst first
#define snd second
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)

int in(){
	char a = getchar();
	int k = 0, kk = 1;
	while(!isdigit(a)){
		if(a == '-') kk = -1;
		a = getchar();
	}
	while(isdigit(a)){
		k = k * 10 + a - '0', a = getchar();
	}
	return k*kk;
}
void out(int a){
	if(a < 0) putchar('-'),a=-a;
	if(a > 9) out(a/10);
	putchar('0'+a%10);
}
const int N = 505, mod = 998244353;
int n,m,c[N];
char s[N];
int p[N];

signed main(){
	FRR("employ.in");
	FRW("employ.out");
	n=in(),m=in();
	scanf("%s",s+1);
	int cnt = 1, ans = 0;
	_rep(i,1,n) c[i] = in(), p[i] = i, cnt = cnt * i;
	_rep(i,1,cnt){
		int f = 0;
		_rep(j,1,n){
			if(f >= c[p[j]]) f++;
			else{
				if(s[j] == 0) f++; 
			}
		}
		if(n-f >= m) ans++;
		next_permutation(p+1,p+1+n);
	}
	cout << ans << endl;
	return 0;
}

