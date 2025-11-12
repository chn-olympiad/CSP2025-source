#include<bits/stdc++.h>
using namespace std;

int n,m;

int f[110],R,r;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n * m; i++){
		
		cin>>f[i];
		
	}
	r = f[1];
	
	sort(f + 1, f + n * m + 1,cmp);
	
	for(int i = 1; i <= n * m; i++){
		if(f[i] == r){
			R = i;
		}
	}
	
//	cout<<R<<'\n';
	
	int L,H;
	
	L = R / n;
	if(R % n != 0){
		L++;
	}
	
	H = (R - 1) % n + 1;
	
	if(L % 2 == 0){
		H = (n + 1) - H;
	}
	
	
	cout << L << " " << H << '\n';
	
	return 0;
}
