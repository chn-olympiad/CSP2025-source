#include<bits/stdc++.h>
using namespace std;
string s;
char t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=s.length()-1;i>=0;i--){
		for(int k=0;k<i;k++){
			if(s[k]<='9'&&s[k]>='0'){
				if(s[k+1]<='9'&&s[k+1]>='0'){
					if(s[k]<s[k+1]){
						t=s[k];
						s[k]=s[k+1];
						s[k+1]=t;
					}
				}
			}
			else{
				if(s[k+1]<='9'&&s[k+1]>='0'){
					t=s[k];
					s[k]=s[k+1];
					s[k+1]=t;
				}
			}
		}
	}
	for(int i=0;(s[i]<='9'&&s[i]>='0');i++){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
