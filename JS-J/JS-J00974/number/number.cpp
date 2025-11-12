#include<bits/stdc++.h>
using namespace std;
long long num[24];
void solve(){
    string s;
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[s[i]-48]++;
        }
    }
    for(long long i=9;i>=0;i--){
        for(long long j=1;j<=num[i];j++){
            cout<<i;
        }
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
     ____________       |
    |      |        _____|______
    |      |             |     |
    | _____|_____        |     |
    |      |            /      |
    /      |  \        /    \  /
   / ______|______    /      \/
                                 
*/