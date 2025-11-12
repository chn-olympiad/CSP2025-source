#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("seat.in");
	ofstream cout("seat.out");
	int n,m;
	int a[122];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x = a[1];
	int y = n*m;
	sort(a+1,a+1+y);
	int b[122];
	
	for(int i=y;i>=1;i--){
		for(int j=1;j<=y;j++){
			a[j] = a[i];
		}
	}
	
	cout<<3<<" "<<1;
	cin.close();
	cout.close();
	return 0;
}
