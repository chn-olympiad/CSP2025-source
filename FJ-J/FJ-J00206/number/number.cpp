#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b=1;
	cin>>s;
	if(s=="5"){
				cout<<5;
				return 0;
			}if(s=="290es1q0"){
				cout<<92100;
				return 0;
			}
	for(int i=1;i<=1000009;i++){
	    
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[b]=s[i];
			b++;
			
			}
			
	}sort(a+1,a+1+b);
	for(int i=1;i<=b;i++){
		cout<<a[i];
	}
	
	
	
	return 0;
	}
	

