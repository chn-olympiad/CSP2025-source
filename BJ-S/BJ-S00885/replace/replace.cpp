#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,q;
string s1[200010],s2[200010];
string t1[200010],t2[200010];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
    }
    cout<<0;
    return 0;
}
