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
    const int MAXN = 1e5+10;
    vector<int> v1,v2,v3;
    int a[MAXN],b[MAXN],c[MAXN],n;
    int GET(vector<int> v,int a[],int b[],int c[]){
        vector<int> d;
        int out = v.size()-n/2;
        for(int i:v){
            d.push_back(a[i]-max(b[i],c[i]));
        }
        sort(d.begin(),d.end());
        int ans = 0;
        for(int i = 0;i<out;i++) ans += d[i];
        return ans;
    }
    signed main(){
        read(n);
        v1.clear();
        v2.clear();
        v3.clear();
        long long sum = 0;
        for(int i = 1;i<=n;i++){
            read(a[i]);
            read(b[i]);
            read(c[i]);
            int maxn = max({a[i],b[i],c[i]});
            sum += maxn;
            if(a[i]==maxn) v1.push_back(i);
            else if(b[i]==maxn) v2.push_back(i);
            else v3.push_back(i);
        }
        if((int)v1.size()>n/2) sum -= GET(v1,a,b,c);
        else if((int)v2.size()>n/2) sum -= GET(v2,b,a,c);
        else if((int)v3.size()>n/2) sum -= GET(v3,c,a,b);
        write(sum,endl);
        return 0;
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T = 1;
    gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
/*
g++ club.cpp -o club -std=c++14 "-Wl,--stack=1000000000" -Wall -Wextra;if($?){echo "running";./club}

*/