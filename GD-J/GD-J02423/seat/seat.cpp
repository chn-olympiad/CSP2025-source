#include<bits/stdc++.h>
using namespace std;

long long n, m, rc, k, ans , d;
long long a[1005];

bool cmp ( int x, int y){
	return x>y;
}

int main(){
	
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w", stdout);
	
	cin >> n >> m;
	k = n*m;
	
	for (int i=1; i<=k; i++){
		cin >> a[i];
	}
	
	rc = a[1]; 
	
	sort ( a+1 , a+k+1 , cmp);
	
	for (int i=1; i<=k; i++){
		if (a[i] == rc){
			ans = i;
			break;
		}  
	}
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			d++;
			if ( d == ans){
				cout << i <<" ";
				if ( i % 2 == 1) cout << j;
				else if (i % 2 == 0) cout << m + 1 - j;
				return 0;
			}
		}
	} 
	return 0; 
}
