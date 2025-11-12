#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=6e5+10;
map<string,string>mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        string a,b;cin>>a>>b;
        mp[a]=b;
        mp[b]=a;
    }
    for(int i=1;i<=q;++i){
        string a,b;cin>>a>>b;
        if(mp[a]==b){
            cout<<1<<endl;
        }
    }

    return 0;
}
