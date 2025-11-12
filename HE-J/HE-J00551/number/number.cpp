#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000005],h[1000005];
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]!='0'||s[i]!='1'||s[i]!='2'||s[i]!='3'||s[i]!='4'||s[i]!='5'||s[i]!='6'||s[i]!='7'||s[i]!='8'||s[i]!='9'){
					cout<<"0";
					return 0;
				}	
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
					a[i]=s[i];
				}
        }  
	sort(a+1,a+s.size()+1);
	for(int i=0;i<s.size();i++){
		h[i]=a[i];
	}
	for(int i=s.size();i>1;i--){
		cout<<h[i];
	}
	return 0;
}
