#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e5+100;
struct dta{
	int s,t;
}a[N];
bool f(dta t,dta c){
	return t.s>c.s;
}
int n,m;

signed main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].s,a[i].t=i;
	sort(a+1,a+1+n*m,f);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j].t==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[(i-1)*n+(n-j+1)].t==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*

*/
