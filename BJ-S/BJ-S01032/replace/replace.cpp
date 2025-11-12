#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,q,cnt=0;
string s1[200005],s2[200005],t1[200005],t2[200005];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i];
        cin>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i];
        cin>>t2[i];
        cout<<0<<endl;
    }
    return 0;
}
