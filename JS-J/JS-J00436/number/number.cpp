#include<bits/stdc++.h>
using namespace std;
char c[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&& s[i]<='9')
            c[cnt++]=s[i];
    }

    sort(c,c+cnt,greater<char>());
    if(c[0]=='0'){
        cout<<0;
        return 0;
    }
    for(int i=0;i<cnt;i++){
        cout<<c[i];
    }
    return 0;
}

