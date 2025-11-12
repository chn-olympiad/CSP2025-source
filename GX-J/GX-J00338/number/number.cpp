#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
string s;
int ton[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            ton[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(ton[i]) cout<<i,ton[i]--;
    }
    return 0;
}
