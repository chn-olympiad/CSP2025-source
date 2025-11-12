#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    string s,t;
    cin>>t;
    for(int i=0;i<t.size();i++) if(t[i]<='9'&&t[i]>='0') s+=t[i];
    sort(s.begin(),s.end(),greater<char>());
    cout<<s;
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
}
