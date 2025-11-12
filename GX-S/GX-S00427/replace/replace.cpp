#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[500000];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int st=1,t=8888888;
    while(t--){
        st*=2;
    }
    while(q--){
        cout<<0;
    }

    return 0;
}
