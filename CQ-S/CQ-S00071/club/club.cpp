#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
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

const int N = 100005;
int a[N][3];
int n;

int c[3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t = in;
    while(t--){
        n = in;
        for(int k=1;k<=n;k++)
            for(int j:{0,1,2})
                a[k][j] = in;
        int ans = 0;
        c[0] = c[1] = c[2] = 0;
        for(int k=1;k<=n;k++){
            int x = 0;
            if(a[k][1]>a[k][x])
                x = 1;
            if(a[k][2]>a[k][x])
                x = 2;

            ans += a[k][x];
            c[x]++;
        }
        int x = 0;
        if(c[1]>c[x])
            x = 1;
        if(c[2]>c[x])
            x = 2;
        
        if(c[x]<n/2){
            out(ans,'\n');
            continue;
        }
        vector<int> w;
        for(int k=1;k<=n;k++){
            int y = 0;
            if(a[k][1]>a[k][y])
                y = 1;
            if(a[k][2]>a[k][y])
                y = 2;

            if(x==y){
                if(!x)
                    w.push_back(-a[k][x]+max(a[k][1],a[k][2]));
                else if(x==1)
                    w.push_back(-a[k][x]+max(a[k][0],a[k][2]));
                else
                    w.push_back(-a[k][x]+max(a[k][0],a[k][1]));
            }
        }
        sort(w.begin(),w.end(),greater<int>());
        w.resize(c[x]-n/2);
        for(int v:w)
            ans += v;
        out(ans,'\n');
    }
}