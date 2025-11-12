#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<=len;i++){
	if(len==1&&s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
		cout<<s;
	}
}
	for(int i=0;i<=len;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
				int tmp;
				if(s[tmp]!='1'||s[tmp]!='2'||s[tmp]!='3'||s[tmp]!='4'||s[tmp]!='5'||s[i]!='6'||s[i]!='7'||s[i]!='8'||s[i]!='9'){
					s[tmp]=s[i];
				}
			}
		}	
	for(int i=0;i<=len-3;i++){
			if(s[i]>s[i+1]){
				cout<<s[i];
			}
			if(s[i]<s[i+1]){
				cout<<s[i+1];
			}
			if(s[i]<s[i-1]&&s[i]<s[i+1]){
				cout<<s[i];
			}
		}
	
 
	return 0;
}
