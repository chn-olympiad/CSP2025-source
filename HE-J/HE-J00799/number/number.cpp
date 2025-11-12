#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	freopen("nember.in","r");
	string s;
	string x;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x+=s[i];
			if(i!=0){
				if(x[i-1]<x[i]){
					swap(x[i-1],x[i]);
				}
			}
		}
	}
	
	int l=x.size();
	for(int i=0;i<l;i++){
		cout<<x[i];
	}
	freopen("nember.out","w");
	return 0;
} 
