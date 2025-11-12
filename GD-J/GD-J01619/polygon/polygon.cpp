#include <bits/stdc++.h>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define pint pair<int,int>
#define fst first
#define snd second
#define int long long

int in(){
	char a=getchar();
	int k=0,kk=1;
	while(!isdigit(a)){
		if(a=='-') kk=-1;
		a=getchar();
	}
	while(isdigit(a)){
		k=k*10+a-'0',a=getchar();
	}
	return k*kk;
}
void out(int a){
	if(a < 0) putchar('-'),a=-a;
	if(a > 9) out(a/10);
	putchar('0'+a%10);
}
#define pb push_back
const int N = 5e3 + 5, mod = 998244353;
int n,a[N];
signed main(){
	FRR("polygon.in");
	FRW("polygan.out");
	n = in();
	_rep(i,1,n) a[i] = in();
	sort(a+1,a+1+n);
	vector <int> last(a[n]*n+1,0);
	last[0] = 1;
	int ans = 0;
	_rep(i,1,n){
		vector <int> tmp(a[n]*n+1,0);
		tmp[0] = 1;
		_rep(j,1,a[n]*i){
			tmp[j]=last[j];
			if(j >= a[i]) tmp[j] = (tmp[j] + last[j-a[i]]) % mod;
		}
		if(i >= 3){
			_rep(j,a[i]+1,a[n]*i){
				ans = (ans + last[j]) % mod;
			}
		}
		last = tmp;
	}
	cout << ans << endl;
	return 0;
}
/*
expect all score : 400 pts

bruh i have more than 76 min to check..

i think it will be many AKer 
*/
