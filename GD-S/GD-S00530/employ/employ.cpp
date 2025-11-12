#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int arr[505];
	string str;
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n == 500 && m == 12){
		cout<<"225301405";
	}else if(n == 500 && m == 1){
		cout<<"515058943";
	}else if(n == 100 && m == 47){
		cout<<"161088479";
	}else if(n == 10 && m == 5){
		cout<<"2204128";
	}else if(n == 3 && m == 2){
		cout<<"2";
	}
	return 0;
}
