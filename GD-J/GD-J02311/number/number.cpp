#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;
	
	cin>>s;
    int a[s.size()],x[s.size()];
	for(int i=0;i<s.size();i++){
		if(s.size()==1){
			cout<<s;
			return 0;
}
		
		
	
	for(int i=0;i<s.size();i++){
		if(a[i]>x[i]){
		x[i]=a[i];
			cout<<a;
		}
		
	}
	
	

	return 0;
}
