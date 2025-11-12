#include<bits/stdc++.h>
//code by twly
//keda is DarSharBee! 
using namespace std;
int c[11];
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			int z=a[i]-'0';
			c[z]++;
		}
	}
	string s;
	int i=9;
	while(i>=0){
		if(c[i]==0){
			i--;
		}
		else{
			s+=i+'0'; 
			c[i]--; 
		}
	}
	cout<<s;
	return 0;
}
