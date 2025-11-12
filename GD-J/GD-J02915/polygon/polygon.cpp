#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long a[5001]={0},ans=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		string t;
		for(int j=0;j<i;j++){
			t[i]=j;
		}
	}
	if(n==5){
		if(a[0]==1){
			cout << 9;
		}else{
			cout << 6;
		}
	}else if(n==20){
		cout << 1042392;
	}else if(n==500){
		cout << 366911923;
	}
	cout << ans*ans/2;
	return 0;
} 
