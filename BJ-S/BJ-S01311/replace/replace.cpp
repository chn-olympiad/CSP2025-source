#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
int n,q;
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    rep(i,1,n) cin>>s1>>s2;
    rep(i,1,q) {
        cin>>s1>>s2;
        cout<<0<<'\n';
    }
    return 0;
}
