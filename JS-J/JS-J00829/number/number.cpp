#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
string s;
long long f[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]-'0'>=0&&s[i]-'0'<=9)f[s[i]-'0']++;
    }
    for(int i=9;i>=0;--i){
        while(f[i]--){
            cout<<i;
        }
    }
    return 0;
}
