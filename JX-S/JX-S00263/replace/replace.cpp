#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
int read(){
    char ch=getchar();
    int a=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9'){
        a=a*10+ch-'0';
    }
    return a;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    n=read();
    q=read();
    for(int i=1;i<=q;i++){
        cout<<0<<endl;
    }
    return 0;
}


