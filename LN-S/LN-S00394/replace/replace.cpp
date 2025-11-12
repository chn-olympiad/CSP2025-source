#include<bits/stdc++.h>
using namespace std;
string s1[100005],s2[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        string t1,t2;cin>>t1>>t2;
        if(t1.size()!=t2.size())cout<<0<<"\n";
        else cout<<1<<"\n";
    }
    return 0;
}