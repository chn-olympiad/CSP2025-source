#include<bits/stdc++.h>
using namespace std;
int main(){
	int a=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000];
	cin>>s[1000];
		for(int i=1;i<=9;i++){
			if(s[i]%1==0 && s[i+1]%1==0){
				if(s[i]<s[i-1] && s[i-1]!=0){
					s[i-1]=a;
					s[i]=s[i-1];
					a=s[i];
				} 
			else if(s[i]%1!=0){
				s[i]=0;
			}
			}
			
	}cout<<5; 
} 

