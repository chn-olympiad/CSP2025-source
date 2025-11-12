#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bits/extc++.h>
using namespace std;

struct{char buf[1<<20],*l=buf,*r=l;
operator char(){return l==r&&(r=(l=buf)+fread(buf,1,1<<20,stdin),l==r)?-1:*l++;}
template<typename T>operator T(){
    T x=0;char f=0,c;
    do if((c=*this)=='-')f=1;while(c<'0'||c>'9');
    while(c>='0'&&c<='9')x=x*10+(c^48),c=*this;
    return f?-x:x;
}}in;void out(char c){putchar(c);}
template<typename T>void out(T x){
    static signed stk[39],tp;
    if(x<0)out('-'),x=-x;
    do stk[tp++]=x%10;while(x/=10);
    while(tp)putchar(stk[--tp]^48);
}template<typename T,typename...Args>
void out(T x,Args...args){out(x),out(args...);}

const int N = 5000005,M = 200005;
const unsigned base1 = 29,base2 = 31,mod1 = 2147483647,mod2 = 1000000007;
char s[N],t[N];
int n,q;

__gnu_pbds::cc_hash_table<unsigned long long,int> h;
__gnu_pbds::cc_hash_table<unsigned long long,basic_string<int>> L[M],R[M];
int idx;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n = in,q = in;
    for(int k=1;k<=n;k++){
        do s[1]=in;while(s[1]<'a'||s[1]>'z');
        int m = 1;
        do s[++m]=in;while(s[m]>='a'&&s[m]<='z');m--;
        for(int k=1;k<=m;k++)
            t[k] = in;

        int l = 1;
        while(l<=m&&s[l]==t[l])
            l++;
        if(l>m)
            continue;
        int r = m;
        while(s[r]==t[r])
            r--;
        
        unsigned h1 = 0,h2 = 0;
        for(int k=l;k<=r;k++){
            h1 = (h1*base1+(s[k]-'a'+1))%mod1;
            h2 = (h2*base2+(s[k]-'a'+1))%mod2;
        }
        for(int k=l;k<=r;k++){
            h1 = (h1*base1+(t[k]-'a'+1))%mod1;
            h2 = (h2*base2+(t[k]-'a'+1))%mod2;
        }
        
        auto &x = h[(1ull*h1)<<32|h2];
        if(!x)
            x = ++idx;

        h1 = h2 = 0;
        for(int k=r+1;k<=m;k++){
            h1 = (h1*base1+(s[k]-'a'+1))%mod1;
            h2 = (h2*base2+(s[k]-'a'+1))%mod2;
        }
        L[x][(1ull*h1)<<32|h2] += k;
        h1 = h2 = 0;
        for(int k=l-1;k;k--){
            h1 = (h1*base1+(s[k]-'a'+1))%mod1;
            h2 = (h2*base2+(s[k]-'a'+1))%mod2;
        }
        R[x][(1ull*h1)<<32|h2] += k;
    }

    while(q--){
        do s[1]=in;while(s[1]<'a'||s[1]>'z');
        int m = 1;
        do s[++m]=in;while(s[m]>='a'&&s[m]<='z');m--;
        for(int k=1;k<=m;k++)
            t[k] = in;

        int l = 1;
        while(s[l]==t[l])
            l++;
        int r = m;
        while(s[r]==t[r])
            r--;
        
        unsigned h1 = 0,h2 = 0;
        for(int k=l;k<=r;k++){
            h1 = (h1*base1+(s[k]-'a'+1))%mod1;
            h2 = (h2*base2+(s[k]-'a'+1))%mod2;
        }
        for(int k=l;k<=r;k++){
            h1 = (h1*base1+(t[k]-'a'+1))%mod1;
            h2 = (h2*base2+(t[k]-'a'+1))%mod2;
        }
        
        auto &x = h[(1ull*h1)<<32|h2];
        if(!x){
            puts("0");
            continue;
        }
        h1 = h2 = 0;

        auto lh = L[x][0],rh = R[x][0];
        for(int k=r+1;k<=m;k++){
            h1 = (h1*base1+(s[k]-'a'+1))%mod1;
            h2 = (h2*base2+(s[k]-'a'+1))%mod2;
            lh += L[x][(1ull*h1)<<32|h2];
        }
        h1 = h2 = 0;
        for(int k=l-1;k;k--){
            h1 = (h1*base1+(s[k]-'a'+1))%mod1;
            h2 = (h2*base2+(s[k]-'a'+1))%mod2;
            rh += R[x][(1ull*h1)<<32|h2];
        }
        if(lh.size()<rh.size())
            swap(lh,rh);
        sort(rh.begin(),rh.end());
        int ans = 0;
        for(int x:lh){
            auto it = lower_bound(rh.begin(),rh.end(),x);
            if(it!=rh.end()&&(*it)==x)
                ans++;
        }
        out(ans,'\n');
    }
}