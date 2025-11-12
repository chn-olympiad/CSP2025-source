#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	string s1;
	for(int i=0;i<s.size();i++){
		if((int)s[i]>=(int)'0'&&(int)s[i]<=(int)'9'){
			s1=s1+s[i];
		}
	}
	char k;
	for(int i=0;i<s1.size();i++){
		for(int j=0;j<s1.size();j++){
			if(s1[j]<s1[j+1]){
				k=s1[j];
				s1[j]=s1[j+1];
				s1[j+1]=k;
			}
		}
	}
	cout<<s1;
	return 0;
} 
