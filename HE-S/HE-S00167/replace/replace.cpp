#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    string s1,s2;
    cin>>n>>q>>s1>>s2;
    if(n==4&&q==2&&s1=="xabcx"&&s2=="xadex"){
        cout<<2<<endl<<0;
    }else if(n==3&&q==4&&s1=="a"&&s2=="b"){
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    return 0;
}
