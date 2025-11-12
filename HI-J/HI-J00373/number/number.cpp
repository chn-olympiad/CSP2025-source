#include<bits/stdc++.h>
using namespace std;
string s,num;
int a[15]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	getline(cin,s);
	if(s.size()==1){
		cout<<s;
	}else{
		
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				a[int(s[i]-'0')]++;
			} 
		}
		
		for(int i=10;i>=0;i--){
			while(a[i]>0){
				num+=i+'0';
				a[i]--;
			}
		}
		
		cout<<num;
		
	}
	
	return 0;
}
