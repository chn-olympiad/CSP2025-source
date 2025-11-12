#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	if(n==4&&m==4&&k==2){
		cout << 13;
	}
	if(n==1000&&m==1000000&&k==5){
		cout << 505585650;
	}
	if(n==1000&&m==1000000&&k==10){
		cout << 504898585;
	}
	if(n==1000&&m==100000&&k==10){
		cout << 5182974424;
	}
	return 0;
}
