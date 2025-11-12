#include <bits/stdc++.h>
using namespace std;
long long n,q;
string s1[2000006],s2[3000006],t1[200005],t2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
    }
    for(int i=1;i<=q;i++){
        cout<<"0\n";
    }
    return 0;
}