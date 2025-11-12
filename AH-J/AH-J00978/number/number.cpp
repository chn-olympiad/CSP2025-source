#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s[1000];
    for(int i=0;i<s;i++){
       cin>>s[i];
    }
    for(int i=0;i<s;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
		   cout<<s[i];
	}
	}
    return 0;
}
