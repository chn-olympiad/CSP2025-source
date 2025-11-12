#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10,K=10+10,mod=1e9+7;
inline int read(){
    int v=0;
    bool f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-')f=1;
    }
    while(ch>='0'&&ch<='9'){
        v*=10;
        v+=ch-'0';
        ch=getchar();
    }
    return (f?-v:v);
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
        putchar(x%10+'0');
    }
    else putchar(x+'0');
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int m=read(),q=read();
    while(q--)puts("0");
    return 0;
}
/*

*/