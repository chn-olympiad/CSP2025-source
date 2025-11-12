#include <bits/stdc++.h>
using namespace std;
long long grad[200], n, m;
bool cmp(long long x, long long y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	long long k=n*m;
	for(long long i=0; i<k; i++){
		cin>>grad[i];
	}
	long long he=grad[0];
	sort(grad, grad+k, cmp);
//	for(long long i=0; i<k; i++){
//		cout<<grad[i]<<endl;
//	}
	for(long long clk=1, x=1, y=1; clk<=k; clk++){
//		prlong longf("now x=%d, y=%d, grad[clk-1]=%d\n", x, y, grad[clk-1]);
		if(grad[clk-1]==he){
			cout<<x<<' '<<y;
			return 0;
		}
		if(x%2==1){
			y++;
			if(y>n){
				y--;
				x++;
			}
		}else{
			y--;
			if(y<=0){
				y++;
				x++;
			}
		}
		
	}
	return 0;
}
