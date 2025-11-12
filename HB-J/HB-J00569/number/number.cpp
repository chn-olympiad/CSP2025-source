#include<bits/stdc++.h>
using namespace std;
string s;
map<int,int>m;
void solve(){
    for(int i=0;i<s.size();++i){
        if(s[i]>='0'&&s[i]<='9')++m[s[i]-'0'];
    }
    for(int i=9;i>=0;--i){
        while(m[i]){
            --m[i];
            printf("%d",i);
        }
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    solve();
    return 0;
}
