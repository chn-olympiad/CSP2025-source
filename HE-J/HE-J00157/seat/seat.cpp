#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,fwd = 0;
	cin >> n >> m >> a;
	for(int i = 1;i < n*m;i++){
		int x;
		cin >> x;
		if(x > a){
			fwd++;
		} 
	}
	fwd++;
	int l = (fwd - fwd%n)/n+1,h = fwd - l*(n-1);
	if(h == 0){
		l--;
		h = m;
	}
	if(l % 2 == 0){
		h = m-h+1;
	}
	cout << l << " " << h;
	return 0;
}
