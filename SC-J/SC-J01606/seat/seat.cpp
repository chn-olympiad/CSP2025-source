#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5+5;
long long i,j,n,m,k,l,x,y,a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n>> m;
	for(i = 1;i <= n*m;i ++){
		cin >>a[i];
	}
	x = a[1];
	sort(a+1,a+n*m+1);
	l = lower_bound(a+1,a+n*m+1,x)-a;
	l = n*m-l+1;
	if(l%m == 0){
		if(l/m % 2 == 0){
			cout <<l/m<<" "<<1;
		}else{
			cout <<l/m<<" "<<n;
		}
	}else{
		if(l/m % 2 == 0){
			cout << l/m+1<<" "<< l%m;
		}else{
			cout << l/m+1<<" "<< n-l%m+1;
		}
	}
	return 0;
}