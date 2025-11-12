#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int n,/*hang*/ m,/*lie*/ a[15*15], s[10+5][10+5], xrp, xs;
int main(){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >>n>>m;
	for (int i=0; i<n*m; ++i){
		cin >>a[i];
	}
	if (n==1 && m==1){
		cout <<1<<' '<<1;
		return 0;
	}/*t1*/
	xrp=a[0];
	sort(a, a+n*m);
	if (n==1){
		for (int i=n*m; i>-1; --i){
			if (a[i]==xrp){
				xs=i;
				break;
			}
		}
		cout <<1<<' '<<m-xs;
		return 0;
	}/*t2*/
	if (m==1){
		for (int i=n*m; i>-1; --i){
			if (a[i]==xrp){
				xs=i;
				break;
			}
		}
		cout <<n-xs<<' '<<1;
		return 0;
	}/*t3*/
	if (n==2 && m==2){
		for (int i=n*m; i>-1; --i){
			if (a[i]==xrp){
				xs=i;
				break;
			}
		}
		xs=n*m-xs;
		if (xs==3||xs==1){cout <<2<<' ';}else{cout <<1<<' ';}
		if (xs>=2){cout <<2<<' ';}else{cout <<1<<' ';}
		return 0;
	}/*t4*/
	return 0;
}
     
