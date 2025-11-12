#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
		char s[10005]={};
		cin>>s;
		int r[10005]={};
		for(int i=0;i<=strlen(s);i++){
			r[i]= s[i]-'a'-'z'-'0';
			}
			for(int i=0;i<=strlen(s);i++){
					if(r[i+1]==0){
					cout<<r[i];
				}
				else if(r[i]>r[i+1]){
					r[i]=r[i+1];
					r[i+1]=r[i];
					}
					cout<<r[i];
				}
	
	
	
	
	
	return 0;
}
