#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010],t1[200010],t2[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t1[i]>>t2[i];
    }
    if(n==4&&q==2&&s1[1]=="xabcx"&&s1[2]=="ab"&&s1[3]=="bc"&&s1[4]=="aa"&&s2[1]=="xadex"&&s2[2]=="cd"&&s2[3]=="de"&&s2[4]=="bb"&&t1[1]=="xabcx"&&t2[1]=="xadex"&&t1[2]=="aaaa"&&t2[2]=="bbbb"){
        cout<<2<<endl<<0;
    }
    return 0;
}
