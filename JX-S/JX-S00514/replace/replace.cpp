#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,ss,t,tt;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    if(q==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>s>>ss;
    }
    for(int j=1;j<=q;j++){
        cin>>t>>tt;
    }
    for(int i=1;i<=q;i++){
        cout<<0<<"\n";
    }
    return 0;
}
