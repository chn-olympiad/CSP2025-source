#include<bits/stdc++.h>
using namespace std;
// /xia LuoFeng_Nanami
int cnt[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    for (int i=0;i<s.size();i++){
        if ('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
    }
    for (int i=9;i>=0;i--){
        for (int qwq=1;qwq<=cnt[i];qwq++) cout<<i;
    }
    return 0;
}