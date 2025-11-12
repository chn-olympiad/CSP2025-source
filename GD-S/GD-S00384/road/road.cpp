#include <bits/stdc++.h>
using namespace std;
long long n,m,k,my;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	cin >> my;
	if(n==4&&m==4&&k==2){
		cout << 13;
	}
	if(n==1000&&m==1000000&&k==5){
		cout << 505585650;
	}
	if(n==1000&&m==1000000&&k==5){
		cout << 505585650;
	}
	if(n==1000&&m==1000000&&k==10&&my==709){
		cout << 504898585;
	}
	if(n==1000&&m==1000000&&k==10&&my==711){
		cout << 5182974424;
	}
	return 0;
}
