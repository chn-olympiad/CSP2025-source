#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
namespace gtx{
    void read(char &x){x=getchar();while(x==' '||x=='\n'||x=='\r');}
    void write(char x){putchar(x);}
    void read(int &x){
        x=0;char ch;int h=1;
        do{ch=getchar();if(ch=='-')h=-h;}while(!isdigit(ch));
        while(isdigit(ch)) x*=10,x+=ch-'0',ch=getchar();
        x*=h;
    }
    void write(int x){
        if(x<0) putchar('-'),x=-x;
        int st[35]={};
        do st[++st[0]]=x%10,x/=10;while(x);
        while(st[0]) putchar(st[st[0]--]+'0');
    }
    void write(int x,char y){
        write(x);write(y);
    }
    #ifndef int
    void read(long long &x){
        x=0;char ch;int h=1;
        do{ch=getchar();if(ch=='-')h=-h;}while(!isdigit(ch));
        while(isdigit(ch)) x*=10,x+=ch-'0',ch=getchar();
        x*=h;
    }
    void write(long long x){
        if(x<0) putchar('-'),x=-x;
        int st[35]={};
        do st[++st[0]]=x%10,x/=10;while(x);
        while(st[0]) putchar(st[st[0]--]+'0');
    }
    void write(long long x,char y){
        write(x);write(y);
    }
    #endif
    const int MAXN = 510;
    int n,m;
    char a[MAXN];
    int c[MAXN];
    int use[MAXN];
    int ans =0 ;
    int L = 0;
    void dfs(int k,int F){
        if(k>n){
            ans += L>=m;
            return;
        }
        for(int i = 1;i<=n;i++){
            if(!use[i]){
                use[i] = 1;
                if(a[k]=='0'||F>=c[i]){
                    dfs(k+1,F+1);
                }else{
                    L++;
                    dfs(k+1,F);
                    L--;
                }
                use[i] = 0;
            }
        }
    }
    signed main(){
        read(n);read(m);
        for(int i = 1;i<=n;i++){
            read(a[i]);
        }
        for(int i = 1;i<=n;++i){
            read(c[i]);
        }
        dfs(1,0);
        write(ans,endl);
        return 0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int T = 1;
    // gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
/*
g++ employ.cpp -o employ -std=c++14 "-Wl,--stack=1000000000" -Wall -Wextra;if($?){echo "running";./employ}
AFOed
*/