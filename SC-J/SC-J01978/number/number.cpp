#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
void solve(){
    cin>>s;
    string ans="";
    for(char c:s)
        if('0'<=c&&c<='9')
            ans+=c;
    sort(ans.begin(),ans.end(),greater<char>());
    while(ans.front()==0)
        ans.erase(ans.begin());
    if(ans.empty())
        cout<<0<<endl;
    else
        cout<<ans<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
/*
O(nlogn) 100pts
*/