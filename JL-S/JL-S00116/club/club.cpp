#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=146097;
int T,y[N],m[N],d[N],n,t;
inline int md(int y,int m){
    if(m==2)return y%4?28:y%100?29:y%400?28:29;
    return m==4||m==6||m==9||m==11?30:31;
}int main(){
    freopen("club",r,stdin)
    freopen("club",w,stdout)
    m[0]=d[0]=1;
    for(int i=1;i<N;++i){
        d[i]=d[i-1]+1;
        m[i]=m[i-1];
        y[i]=y[i-1];
        if(d[i]>md(y[i],m[i]))++m[i],d[i]=1;
        if(m[i]>12)++y[i],m[i]=1;
    }
    scanf("%d",&T);
    while(T--){
            scanf("%||d",&n);
    if(n>=2299160){
            n-=2159351;
            t=n/N*400+1200;
            n%=N;
    }else{
        t=n/1461*4-4712;
        n%=1461;
        }
            if(t+y[n]>0)printf("%d %d %||d\n",d[n],m[n],t+y[n]);
            else printf("%d %d %||d BC\n",d[n],m[n],1-t-y[n]);
        }
    }
