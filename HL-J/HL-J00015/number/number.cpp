#include <bits/stdc++.h>
using namespace std;
string s;
string c;
string c9;
string c8;
string c7;
string c6;
string c5;
string c4;
string c3;
string c2;
string c1;
string c0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
		
		if(s[i]=='9'){
			c9+=s[i];
		}else if(s[i]=='8'){
			c8+=s[i];
		}else if(s[i]=='7'){
			c7+=s[i];
		}else if(s[i]=='6'){
			c6+=s[i];
		}else if(s[i]=='5'){
			c5+=s[i];
		}else if(s[i]=='4'){
			c4+=s[i];
		}else if(s[i]=='3'){
			c3+=s[i];
		}else if(s[i]=='2'){
			c2+=s[i];
		}else if(s[i]=='1'){
			c1+=s[i];
		}else if(s[i]=='0'){
			c0+=s[i];
		}
	}
	}
	if(c9.size()>=1){
		c+=c9;
	}
	if(c8.size()>=1){
		c+=c8;
	}
	if(c7.size()>=1){
		c+=c7;
	}
	if(c6.size()>=1){
		c+=c6;
	}
	if(c5.size()>=1){
		c+=c5;
	}
	if(c4.size()>=1){
		c+=c4;
	}
	if(c3.size()>=1){
		c+=c3;
	}
	if(c2.size()>=1){
		c+=c2;
	}
	if(c1.size()>=1){
		c+=c1;
	}
	if(c0.size()>=1){
		c+=c0;
	}
	cout<<c;
}
