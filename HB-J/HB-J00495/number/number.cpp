#include <bits/stdc++.h>
using namespace std;
int num[10];
string s;
bool flag;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9') num[s[i]-'0']++;
        if(num[s[i]-'0']&&s[i]!='0') flag=1;
    }
    if(!flag) cout<<0;
    else{
        for(int i=9;i>=0;i--){
            while(--num[i]>=0) cout<<i;
        }
    }
    return 0;
}
