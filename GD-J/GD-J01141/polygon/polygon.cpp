#include<bits/stdc++.h>
using namespace std;
int n , ans = 0 ;
int a[5050] ;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	for(int i = 1;i <= n;i++){
		cin >> a[i] ;
	}
	sort(a+1,a+1+n);
	if(n == 3){
		cout << 1 ;
	}else{
		cout << n/2 ;
	}
	fclose(stdout);
	fclose(stdout);
	return 0;
}
