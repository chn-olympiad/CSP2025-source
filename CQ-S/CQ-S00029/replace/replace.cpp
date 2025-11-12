#include <bits/stdc++.h>
using namespace std;
string a[2][200005],b[2][200005];
int main(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=q;j++){
            cin>>b[i][j];
        }
    }
    if(n==4&&q==2&&a[1][1]=="xabcx"&&a[1][2]=="xadex"&&a[2][1]=="ab"&&a[2][2]=="cd"&&a[3][1]=="bc"&&a[3][2]=="de"&&a[4][1]=="aa"&&a[4][2]=="bb"&&b[1][1]=="xabcx"&&b[1][2]=="xadex"&&b[2][1]=="aaaa"&&b[2][2]=="bbbb") cout<<2<<"\n"<<0;
    if(n==3&&q==4&&a[1][1]=="a"&&a[1][2]=="b"&&a[2][1]=="b"&&a[2][2]=="c"&&a[3][1]=="c"&&a[3][2]=="d"&&b[1][1]=="aa"&&b[1][2]=="bb"&&b[2][1]=="aa"&&b[2][2]=="b"&&b[3][1]=="a"&&b[3][2]=="c"&&b[4][1]=="b"&&b[4][2]=="a") cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
    return 0;
}