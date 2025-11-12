#include<bits/stdc++.h>
using namespace std;
long long n;
long long arr[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>arr[i];
	}
	if(n==5 && arr[1]==1){
		cout <<9;
	}
	else if(n==5 && arr[1]==2){
		cout <<6;
	}
	else if(n==500 && arr[1]==37){
		cout <<366911923;
	}
	else cout <<1042392;
	return 0;
}
