#include<bits/stdc++.h>
using namespace std;
string a;
int f[10005],c[10005],g[10005],v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a>>v;
    for(int i=0;i<=v;i++){
        f[i]=a[i];
        if(f[i]==48||f[i]==49||f[i]==50||f[i]==51||f[i]==52||f[i]==53||f[i]==54||f[i]==55||f[i]==56||f[i]==57){
            c[i]=f[i]-48;
        }
    }
    for(int j=0;j<=v;j++){
        cout<<c[j];
    }
    return 0;
}

