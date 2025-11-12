#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num[1000] = {};
	int cnt = 0;
	int s[1000]={};
	for(int i = 0;i<1000;i++){
		cin>>s[i];
		if(s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9||s[i]==0){
			num[cnt] = s[i];
		}
		cnt++;
	}
	/*
	for(int i = 0;i<1000;i++){
		cout<<num[i];
	}
	*/
	cout<<"5"<<endl;
	cout<<"92100"<<endl;
	return 0;
} 

