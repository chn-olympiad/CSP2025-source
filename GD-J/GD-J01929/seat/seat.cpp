#include<bits/stdc++.h>
using namespace std;
int a[104];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i]; 
	} 
	int f = a[1];
	int nm = n*m;
	sort(&a[1],&a[nm + 1]);
	reverse(&a[1],&a[nm + 1]);
//	for(int i = 1; i <= nm; i++)cout << a[i] <<' ';
	for(int i = 1; i <= nm; i++){
		if(a[i] == f){
			if(((i - 1) / n + 1) % 2 == 1){
				if(i % n == 0)cout  << i / n   << ' ' << n;
				else cout  << i / n + 1 <<' '<< i % n;
				break;			 
			}
			else{
				if(i % n == 0)cout  << i / n  << ' ' << 1;
				else cout << i / n + 1 <<' '<< n - i % n + 1;
				break; 
			}
		}
	} 
}
