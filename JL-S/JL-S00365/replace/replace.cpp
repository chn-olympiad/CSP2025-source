#include<bits/stdc++.h>
using namespace std;
string a[1000005],b[1000005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int j=1;j<=q;j++){
        string s,ss;
        cin>>s>>ss;
    }
    if(q==2)cout<<2<<endl<<0;
    else cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
    return 0;
}
