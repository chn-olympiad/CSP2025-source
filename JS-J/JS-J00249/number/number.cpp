#include<bits/stdc++.h>
using namespace std;
string s;
int num[15];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i]))num[(int)(s[i]-'0')]++;
    }
    for(int i=9;i>=0;i--){
        while(num[i]--)printf("%d",i);
    }
    return 0;
}
