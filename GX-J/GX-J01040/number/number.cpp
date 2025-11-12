#include <bits/stdc++.h>

using namespace std;

int main(){
freopen("number.in","r",stdin);
freopen("number.in","r",stdout);


string s;
cin>>s;
int l=s.length();

for(int i=9;i>=0;i--){
    for(int j=0;j<l;j++){
        if(s[j]<='9'&&s[j]>='0'){
            if(i+'0'==s[j]){
                cout<<s[j];
            }
        }
    }
}


return 0;
}
