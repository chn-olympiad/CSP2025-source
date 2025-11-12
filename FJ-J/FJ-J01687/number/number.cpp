#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++){
		for(int j=i-1;j<i;j++){
			if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
				if(s[i]<s[i+1]){
					s[j]=s[i];
					s[i]=s[i+1];
					s[i+1]=s[j];
				}
				cout<<s[i];
				break;
			}
		}
	}
			 
	return 0;	
}