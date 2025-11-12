#include<bits/stdc++.h>
using namespace std;
inline char gtchar(){
    static char buf[1000005],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000005,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=gtchar();
    int x=0;
    while(ch<'0'||ch>'9') ch=gtchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gtchar();
    return x;
}
int t,n,maxn,maxx,pos,num[5],to,ans;
priority_queue<int,vector<int>,greater<int> > q[5];
inline void solve(int x){
    while(num[x]>to){
        int tmp=q[x].top();
        ans-=tmp,q[x].pop(),num[x]--;
    }
    num[x]=0;
    while(!q[x].empty()) q[x].pop();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read(),to=n/2,ans=0;
        for(int i=1;i<=n;i++){
            maxn=maxx=pos=-1;
            for(int j=1,x;j<=3;j++){
                x=read();
                if(x>maxn) maxx=maxn,maxn=x,pos=j;
                else if(x>maxx) maxx=x;
            }
            ans+=maxn,num[pos]++,q[pos].emplace(maxn-maxx);
        }
        solve(1),solve(2),solve(3),printf("%d\n",ans);
    }
    return 0;
}