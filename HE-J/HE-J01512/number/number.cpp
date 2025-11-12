#include<bits/stdc++.h>
using namespace std;
const int MX=20,INF=0x3f3f3f3f;
int ton[MX];
void solve(){
    string s;cin>>s;
    int len=s.size();
    s=" "+s;
    for(int i=1;i<=len;i++)  ton[s[i]-'0']++;
    for(int i=9;i>=0;i--){
        while(ton[i]){
            printf("%d",i);
            ton[i]--;
        }
    }

    return ;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int T=1;
    while(T--)  solve();
    return 0;
}
