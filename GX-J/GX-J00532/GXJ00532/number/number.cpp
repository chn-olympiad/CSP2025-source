#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char arr[1000000]={};
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			arr[i]=s[i];
		}
	}
	sort(arr,arr+1000000,cmp);
	for(int i=0;i<s.length();i++){
		if(arr[i]=='0')cout<<0;
		else if(arr[i]=='1')cout<<1;
		else if(arr[i]=='2')cout<<2;
		else if(arr[i]=='3')cout<<3;
		else if(arr[i]=='4')cout<<4;
		else if(arr[i]=='5')cout<<5;
		else if(arr[i]=='6')cout<<6;
		else if(arr[i]=='7')cout<<7;
		else if(arr[i]=='8')cout<<8;
		else if(arr[i]=='9')cout<<9;
	}
	
	return 0;
}
