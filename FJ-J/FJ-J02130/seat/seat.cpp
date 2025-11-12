#include<bits/stdc++.h>
using namespace std;
struct xr{
	int a1;
	int an = 1;
	int am = 1;
}rr;
int n,m,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i <= n*m - 1;i++){
		if(i == 0){
			cin >> rr.a1;
			continue;
		}else{
			cin >> a;
		}
		if((a > rr.a1)&&(rr.am % 2==1)){
			rr.an++;
			if(rr.an > n){
				rr.an = n;
				rr.am++;
			}
			continue;
		}x[r]
		if((a > rr.a1)&&(rr.am % 2==0)){
			rr.an--;
			if(rr.an < 1){
				rr.an = 1;
				rr.am++;
			}
			continue;
		}
	}
	cout << rr.am << ' ' << rr.an;
	return 0;
}
