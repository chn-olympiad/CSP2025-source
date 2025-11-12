#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long ;
const int N = 100005;

inline ll read(){
	ll ret = 0, sym = 1;  char c = getchar();
	while(!(c >= '0' && c <= '9'))  {if(c == '-') sym = -1;  c = getchar();}
	while(c >= '0' && c <= '9')  {ret = ret * 10ll + c - '0'; c = getchar();}
	return ret * sym;
}

void print(ll x, char inter){
	if(x < 0) x = -x, putchar('-');
	if(x > 9) print(x / 10ll, '\0');
	putchar(x % 10ll + '0');
	if(inter)  putchar(inter);
}

int n ;

struct person{
	ll v[4];
	int best, sec;
	ll cost;
}a[N];
int cnt[4];

void solve(){
	n = read();
	for(int i=1; i<=n; ++ i){
		ll mx = 0, mxi = 0, se = 0, sei = 0;
		for(int j=1; j<=3; ++ j){
			a[i].v[j] = read();
			if(a[i].v[j] > mx){
				se = mx, sei = mxi;
				mx = a[i].v[j], mxi = j;
			}else if(a[i].v[j] > se){
				se = a[i].v[j], sei = j;
			}
		}
		a[i].best = mxi, a[i].sec = sei, a[i].cost = mx - se;
		++ cnt[a[i].best];
	}
	
	sort(a+1, a+n+1, [](person i, person j)->bool{
		if(i.best == j.best)  return i.cost > j.cost;
		return cnt[i.best] > cnt[j.best];
	});
	
	int most = a[1].best;
	ll ans = 0;
	for(int i=1; i<=n; ++ i){
		if(i > n / 2 && a[i].best == most){
			ans += a[i].v[a[i].sec]; 
		}else{
			ans += a[i].v[a[i].best];
		}
	}
	print(ans, '\n');
	
	for(int i=1; i<=n; ++ i){   //clear
		for(int j=0; j<=3; ++ j){
			a[i].v[j] = 0;
		}
		a[i].best = a[i].sec = a[i].cost = 0;
	}
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T = read();
	while(T -- ){
		//clear
		
		solve();
	}
	return 0;
}
