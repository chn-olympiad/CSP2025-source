#include <bits/stdc++.h>
using namespace std;
string s;
long long li[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.length();i++){
        if(s[i]>='0' and s[i]<='9')
            li[s[i]-'0']++;
    }
    for(long long i=9;i>=0;i--){
        while(li[i]){
            cout<<i;
            li[i]--;
        }
    }
    return 0;
}
