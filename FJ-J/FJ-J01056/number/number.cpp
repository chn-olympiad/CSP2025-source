#include<bits/stdc++.h>
using namespace std;
char zdz='0';
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	cin>>s;
	if(s>='0'&&s<='9'){
		cout<<s;
	}
	else{
		while(s--){
			if(s>zdz){
				zdz=s;
			}
			s+=zdz;
		}
		cout<<s;	
	}
	return 0;
} 
