#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],k,ans,s[500];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>> n >> m;
	k = m * n + 1;
	for(int i = 1; i <= n * m; i++){
		cin>> s[i];
	}
	ans = s[1];
	sort(s + 1,s + n * m + 1);
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= m; j++){
				k--;
				if(s[k] == ans){
					cout<< i << ' ' << j;
				}
			} 
		}
		else{
			for(int j = m; j > 0; j--){
				k--;
				if(s[k] == ans){
					cout<< i << ' ' << j;
				}
			} 
		}
	}		
	return 0;
} 