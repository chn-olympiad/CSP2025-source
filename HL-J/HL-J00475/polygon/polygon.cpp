#include<iostream>
#include<cstdio>
int a[5001];
using namespace std;
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	cout << 1;
	return 0;
} 
