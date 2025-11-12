#include<bits/stdc++.h>
using namespace std;
int n , lo[20000] , d[20000] , dl=1 , ans = 0;
void p()
{
	if(dl<3) return ;
	int big = 0, he = 0;
	for(int i = 1;i <= dl;++i) {
		he+=lo[d[i]];
		if(big < lo[d[i]]) big = lo[d[i]];
	}
	if(big*2<he) ans++;
}
void dg(int m){
	for(int i = m;i <= n;++i){
		d[dl] = i;
		p();
		dl++;
		dg(i+1);
		dl--;
	}
	return ;
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> lo[i];
	dg(1);
	cout << ans % 998244353;
	return 0;
}

