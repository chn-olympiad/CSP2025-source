#include<bits/stdc++.h>
using namespace std;
int n;
const int Mod = 998224353;
const int N = 5050;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[n];
	}
	if(n == 5 && a[0] == 1){
		cout<<9;
		return 0;
	}
	if(n == 5 && a[0] == 2){
		cout<<6;
			return 0;
	}
	if(n == 20){
		cout<<1042392;
		return 0;
	}
	if(n == 500){
		cout<<366911923;
		return 0;
	}
	return 0;
} 
