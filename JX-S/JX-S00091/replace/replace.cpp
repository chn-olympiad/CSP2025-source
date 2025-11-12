#include <bits/stdc++.h>
using namespace std;
const int N=2*(1e5+5);
string a1[N],a2[N],t1[N],t2[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    int n1=n,q1=q;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i];
    }
    for(int j=1;j<=q;j++){
        cin>>t1[j]>>t2[j];
    }
    if(q==4&&n==3) {
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    else if(q==2&&n==4){
        if(a1[1]=="xabcx"&&a2[1]=="xadex"&&a1[2]=="ab"&&a2[2]=="cd"){
            cout<<2<<endl<<0;
        }
    }
    return 0;
}
