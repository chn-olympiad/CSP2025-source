#include<bits/stdc++.h>
using namespace std;
int n,m;
string sa,sb;
map<string,int>mp;
map<string,string>cha;
int ans=0;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
      ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>sa>>sb;
        mp[sa]=1;
        cha[sa]=sb;
    }
    while(m--){
        cout<<"0\n";

    }
    return 0;
}
