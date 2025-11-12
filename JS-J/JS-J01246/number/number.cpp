#include<bits/stdc++.h>
using namespace std;
int cnt[11];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]-'0'<10){
            ++cnt[s[i]-'0'];
        }
    }
    for(int i=9;i>=0;--i){
        for(int j=1;j<=cnt[i];++j){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
