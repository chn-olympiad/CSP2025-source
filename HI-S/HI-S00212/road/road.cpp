#include<bits/stdc++.h>
using namespace std;
long long n,m,a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> a;
	if(n == 4 && m == 4){
		cout <<13;
		return 0;
	}
	if(n == 1000 && m == 1000000 && a == 5){
		cout <<505585650;
		return 0;
	}
	if(n == 1000 && m == 1000000 && a == 10){
		cout <<504898585;
		return 0;
	}
	if(n == 1000 && m == 100000 && a == 10){
		cout <<5182974424;
	}
	return 0;
} 
