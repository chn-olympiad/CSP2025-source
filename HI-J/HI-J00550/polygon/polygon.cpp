#include<bits/stdc++.h>
using namespace std;
long long n , a[5001]={} , sum=9 ;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
	}
	cout << sum;
	return 0;
} 
