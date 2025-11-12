#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct A{
    int a,b,c;
    bool operator < (const A &aa)const{
        return min(a-b,a-c) < min(aa.a-aa.b,aa.a-aa.c);
    }
}f[N];
struct B{
    int a,b,c;
    bool operator < (const B &bb)const{
        return min(b-a,b-c) < min(bb.b-bb.a,bb.b-bb.c);
    }
}s[N];
struct C{
    int a,b,c;
    bool operator < (const C &cc) const{
        return min(c-a,c-b) < min(cc.c-cc.a,cc.c-cc.b);./club
    }
}t[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w".stdout);
    int T;cin>>T;
    for(int tt=1;tt<=T;tt++){
        cin>>n;
        int t1=0,t2=0,t3=0,ans=0;
        for(int i=1;i<=n;i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(u>=v && u>=w){
                t1++;ans+=u;
                f[t1]={u,v,w};
            }else if(v>=u && v>=w){
                t2++;ans+=v;
                s[t2]={u,v,w};
            }else{
                t3++;ans+=w;
                t[t3]={u,v,w};
            }
        }
        if(t1<=n/2 && t2<=n/2 && t3<=n/2){
            cout<<ans<<'\n';
            continue;
        }else if(t1>n/2){
            sort(f+1,f+t1+1);
            int tmp=t1;
            for(int i=1;i<=t1;i++){
                ans-=f[i].a;
                ans+=max(f[i].b,f[i].c);
                tmp--;
                if(tmp<=n/2) break;
            }
            cout<<ans<<'\n';
        }else if(t2>n/2){
            sort(s+1,s+t2+1);
            int tmp=t2;
            for(int i=1;i<=t2;i++){
                ans-=s[i].b;
                ans+=max(s[i].a,s[i].c);
                tmp--;
                if(tmp<=n/2) break;
            }
            cout<<ans<<'\n';
        }else{
            sort(t+1,t+t3+1);
            int tmp=t3;
            for(int i=1;i<=t3;i++){
                ans-=t[i].c;
                ans+=max(t[i].a,t[i].b);
                tmp--;
                if(tmp<=n/2) break;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}