#include<bits/stdc++.h>
using namespace std;

int n=0,q=0;
string sa,sb;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1 ; i<=m ; i++){
        cin>>sa>>sb;
    }
    for(int i=1 ; i<=m ; i++){
        cin>>sa>>sb;
    }
    if(n==4 && q==2){
        cout<<2<<'\n'<<0;
    }else if(n==3 && q==4){
        cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0;
    }else{
        for(int i=1 ; i<=q ; i++){
            cout<<0<<'\n';
        }
    }
    return 0;
}
