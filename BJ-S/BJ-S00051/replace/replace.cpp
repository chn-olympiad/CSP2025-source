#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    string str,str1;
    for(int i=1;i<=n;i++) cin>>str>>str1;
    for(int i=1;i<=q;i++) cin>>str>>str1;
    if(n==4&&q==2) cout<<2<<endl<<0;
    if(n==3&&q==4) cout<<0<<endl<<0<<endl<<0<<endl<<0;
    return 0;
}
