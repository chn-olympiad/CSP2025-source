#include<bits/stdc++.h>

using namespace std;

int sj(int seed){
	unsigned int c = pow(2,31);
	return (seed*213014+251101)%c;
}

int n,m;
string in;
int c[10001];

int main(){
	int seed;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin >> n >> m;
	cin >> in;
	for(int i = 0 ;i < n ; i++){
		cin >> c[i];
		seed += c[i];
	}
	
	for(int i = 0 ; i < n ; i++){
		seed = sj(seed+i*1024);
	}cout << abs(seed%998244353);
	return 0;
}
