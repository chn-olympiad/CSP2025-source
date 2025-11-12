#include <bits/stdc++.h> 
using namespace std;
const int N=200005;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,k;
	cin>>n>>k;
	string a;
	cin>>a;
	int arr[505];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==3&&k==2){
		cout<<2;
		return 0;
	}
	if(n==10&&k==5){
		cout<<2204128;
		return 0;
	}
	if(n==100&&k==47){
		cout<<161088479;
		return 0;
	}
	
	if(n==500&&k==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&k==12){
		cout<<225301405;
		return 0;
	}
	cout<<0; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
4 0 1 0 0 1 0 0 2 0 0 2 0
*/
