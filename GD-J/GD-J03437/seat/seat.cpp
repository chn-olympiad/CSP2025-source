#include<bits/stdc++.h>
using namespace std;
bool twp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,test,w;
	cin >> n >> m;
	long long a[1001];
	for(long long i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	test = a[1];
	sort(a+1,a+n*m+1,twp);
	for(long long i = 1;i <= n*m;i++){
		if(a[i] == test){
			w = i;
		}
	}
	long long x,y;
	if(w % 2 == 0){
		x = w/n;
	}else{
		x = w/n + 1;
	}
	cout << x << " ";
	if(x % 2 == 1){
		long long s = x*n;
		for(long long i = s-n+1;i <= s;i++){
			if(i == w){
				cout << i%n;
			}
		}
	}else{
		long long s = x*n;
		y = n;
		for(long long i = s-n+1;i <= s;i++){
			if(i == w){
				cout << y;
			}
			y--; 
		}
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
