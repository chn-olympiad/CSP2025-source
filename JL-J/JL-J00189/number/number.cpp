#include <bits/stdc++.h>
using namespace std;
int num[1005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int t= 1;
    for(int i = 0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(s[i]=='0') num[t]=0;
            if(s[i]=='1') num[t]=1;
            if(s[i]=='2') num[t]=2;
            if(s[i]=='3') num[t]=3;
            if(s[i]=='4') num[t]=4;
            if(s[i]=='5') num[t]=5;
            if(s[i]=='6') num[t]=6;
            if(s[i]=='7') num[t]=7;
            if(s[i]=='8') num[t]=8;
            if(s[i]=='9') num[t]=9;

            t++;
        }
    }
    sort(num,num+t);
    for(int i = t-1;i>=1;i--){
        cout<<num[i];
    }
    return 0;
}
