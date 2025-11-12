#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    sort(s,s+strlen(s));
    for(int i=strlen(s)-1;i>=0;i--){
    	if(0<=s[i]-'0'and s[i]-'0'<=9){
    		cout<<s[i];
		}
	}
	return 0;
} 
