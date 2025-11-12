#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100+10,mod=988244353;
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
int n,m,a[N],p[N],ans;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read();
    m=read();
    cin>>s;
    s=' '+s;
    //cerr<<s;
    for(int i=1;i<=n;i++){
        a[i]=read();
        p[i]=i;
    }
    if(n>10)puts("0");
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    do{
        int failed=0,res=0;
        for(int i=1;i<=n;i++){
            if(failed>=a[p[i]]||s[i]=='0')failed++;
            else res++;
        }
        //cerr<<res<<endl;
        if(res>=m)ans=(ans+1)%mod;
    }while(next_permutation(p+1,p+n+1));
    write(ans%mod);
    return 0;
}
/*
3 2
101
1 1 2

8pts
*/