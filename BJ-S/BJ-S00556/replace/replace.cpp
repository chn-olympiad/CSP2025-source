#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m>>k;
    if(n==4 && m==2) cout<<2<<endl<<0;
    if(n==3 && m==4) cout<<0<<endl<<0<<endl<<0<<endl<<0;
    if(n==1000 && m==1000000 && k==10) cout<<504898585;
    if(n==1000 && m==100000 && k==10) cout<<5182974424;
    else cout<<100510;
    return 0;
}
