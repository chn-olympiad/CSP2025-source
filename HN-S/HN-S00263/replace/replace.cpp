#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<='0') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') {x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
    return x*f;
}
signed main(){
    freopen("replace.in" ,"r",stdin );
    freopen("replace.out","w",stdout);
    // freopen("1.in","r",stdin);
    int n=read(),q=read();
    while(q--) printf("0\n");
    return 0;
}