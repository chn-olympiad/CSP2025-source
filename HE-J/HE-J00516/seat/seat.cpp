#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,total;
	cin >> n >> m;
	total = n*m;
	int ns[total+1] = {};
	int pos[n+1][m+1] = {};
	for(int i=1;i<=total;i++){
		cin >> ns[i];
	}
	const int r = ns[1];
	sort(ns,ns+total+1,cmp);
	int iz = 0;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				if(ns[iz]>=0)pos[i][j] = ns[iz++]; 
			}
		}
		else{
			for(int j=m;j>0;j--){
				if(ns[iz]>=0)pos[i][j] = ns[iz++]; 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(pos[i][j]==r){
				cout << i << ' ' << j << endl;
				break;
			}
		}
	}
	return 0;
} 
