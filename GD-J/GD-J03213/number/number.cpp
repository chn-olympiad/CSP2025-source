#include<bits/stdc++.h>
using namespace std;
string s;
int k[210];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            k[(s[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(k[i]>0){
            while(k[i]--)cout<<i;
        }
    }
    return 0;
}