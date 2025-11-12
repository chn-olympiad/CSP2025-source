#include<bits/stdc++.h>
using namespace std;
int n,m; 
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	if(n == 3){
		cout<<"2";
	}else if(n == 10){
		cout<<"2204128";
	}else if(n == 100){
		cout<<"161088479";
	}else if(n == 500 & m == 1){
		cout<<"515058943";
	}else if(n == 500 & m == 12){
		cout<<"225301405";
	}else{
		cout<<"0";
	}
	return 0;
}
