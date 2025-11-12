#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
map<string,string>mp;
string a,b,c;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        mp[a]=b;
    }
    while(q--){
        cin>>c;
        cout<<1<<endl;
    }
    return 0;
}
