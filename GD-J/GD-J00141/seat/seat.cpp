#include<bits/stdc++.h>

using namespace std;
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int k,n,m,big = -1;
	int c,r;
	int a[105];
	int score[105];
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
		if(a[i] > big){
			big = a[i];
			k = i;
		}
	}
	if(big == a[1]){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i = 1;i <= n*m;i++){
		if(big == a[1]){
			k = i;
			break;
		}
		score[i] = big;
		a[k] = -1;
		big = -1;
		for(int j = 1;j <= n*m;j++){
			if(a[j] > big){
			big = a[j];
			k = j;
			}
		}
	}
	if(k % n == 0){
		c = k / n;
	}else{
		c = k / n + 1;
	}
	if(c % 2 == 1){
			r = k % n;
			if(r == 0){
				r = m;
			}
		}else{
			r =  m - (k + m - 1) % n;
		}
	cout<<c<<" "<<r;

	return 0;

}
