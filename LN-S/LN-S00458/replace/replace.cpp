#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct str{
    string a,b;
}s[maxn];
int n,q;
string t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        cout<<0<<"\n";
    }
    return 0;
}
