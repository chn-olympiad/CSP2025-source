#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[100];
	int n,number = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	if(n==3){
		if(a[0]+a[1]>a[2] || a[0]+a[2]>a[1] || a[1]+a[2]>a[0]){
			number++;
		}
		cout <<number;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
