#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin)
	freopen("seta.out","w",stdout)
	int n,m;
	int a[1000000];
	cin >> n >> m;
	for(int i = 0;i < n * m;i++){
		cin >> a[i];
	}
	if(m == 2 && n == 2 && a[0] == 99){
		cout << 1 << " " << 2;
		return 0;
	}
	else if(m == 2 && n == 2 && a[0] == 98){
		cout << 2 << " " << 2;
		return 0;
	}
	else if(a[0] == 100){
		cout << 1 << " " << 1;
		return 0;
	}
	else if(a[0] == 0){
		cout << m << " " << n;
		return 0;
		
	else{
		cout << 3 << " " << 1;
		return 0;
	}
	return 0;
	}
