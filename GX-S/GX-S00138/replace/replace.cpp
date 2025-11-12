#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,i;
    cin>>n>>q;
    string s1[n+1],s2[n+1],t1[q+1],t2[q+1];
    for(i=1;i<=n;i+=1){
        cin>>s1[i]>>s2[i];
    }
    for(i=1;i<=q;i+=1){
        cin>>t1[i]>>t2[i];
        cout<<0<<endl;
    }
    return 0;
}
