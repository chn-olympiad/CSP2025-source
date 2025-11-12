#include <bits/stdc++.h>
using namespace std;
	
	int number[12];
	char in;
	
	int main(){
		
	while(cin>>in){
		if(in>='0'&&in<='9'){
			number[in-'0']++;
		}
	}
	
	for(int i=10;i>=0;i--){
		for(int j=number[i];j>0;j--)
		cout<<i;
	}
	return 0;
}