#include<bits/stdc++.h>

using namespace std;
const int N = 5e3 + 5;
int main(){
	
	freopen("polygon.in" ,"r" ,stdin);
	freopen("polygon.out" ,"w" ,stdout);
	
	
	int n;
	cin >> n;
	for(int i=1; i <= n;i++){
		cin >> a[i];
	} 
	
	if (n < 3) {
		cout << 0;
	} 
	
	if(n == 3) {
		cout << 1;
	} 
	
	
    
	return 0;
}
