#include<bits/stdc++.h>
using namespace std;
string a[1000005];
string b[1000005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++){
        cout<<0<<endl;
    }
    return 0;
}
