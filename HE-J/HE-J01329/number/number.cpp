#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str;
	cin >> str;
	int len=str.length();
	int arr[1000]={};
	
	for(int i=0;i<len;i++){
		arr[str[i]-'0']++;
	}
	
	for(int i=9;i>=0;i--){
		for(int j=0;j<arr[i];j++){
			cout << i;
		}
	}
	
	return 0;
}
