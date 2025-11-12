#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    string q="";
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9')q+=s[i];
    }
    sort(q.begin(),q.end());
    reverse(q.begin(),q.end());
    cout<<q;
    return 0;
}
