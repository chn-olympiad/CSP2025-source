#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int ar = 0;
	int n,m;cin >> n >> m;int t = n*m;
	int in[n*m];for(int i = 0;i < n*m;i++){
		cin >> in[i];
	}
	int r = in[0];
	int p = 0;
	sort(in,in +t,greater<int>());
	for(int i = 0;i < t;i++){
		if(in[i] == r){
			p = i+1;break;
			
		}
	}
	int lie = 0;	
	for(int i = 1;i <= m;i++){
		if(i*n >= p){
			lie = i;break;
		}
	}	
	if(p<=n){
		cout << lie << " " << p;return 0;
	}
	
	
	
	if(lie%2 == 0){
		cout << lie;
		cout << ' ';
		cout << n-p%n+1;
	}	else{
			cout << lie;
		cout << ' ';
		cout << p%n;
	}
		
	return 0;
}
