#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0,best1,best2,best3,t;
bool a2equ0=1,a3equ0=1,a1equ0=1;
struct fenpei{
    ll a1,a2,a3;
    int best,second,last;
}chi[100005];
bool cmp(fenpei p,fenpei q){
    return p.a1>q.a1;
}
bool cmp1(fenpei p,fenpei q){
    return p.a2>q.a2;
}
bool cmp2(fenpei p,fenpei q){
    return p.a3>q.a3;
}
/*bool cmp1(fenpei p,fenpei q){
    if(p.best!=q.best){
        return p.best<q.best;
    }
    if(p.best==1) return p.a1>q.a1;
    return p.a2>q.a2;
}
bool cmp2(fenpei p,fenpei q){
    if(p.best!=q.best){
        return p.best>q.best;
    }
    if(p.best==2) return p.a2>q.a2;
    return p.a1>q.a1;
}*/
ll dfs(ll dangqian,ll p1,ll p2,ll p3,ll res){
    //////cout<<dangqian<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<res<<"\n\n";
    if(dangqian>=n) return res;
    if(p1==n/2) return max(dfs(dangqian+1,p1,p2+1,p3,res+chi[dangqian+1].a2),dfs(dangqian+1,p1,p2,p3+1,res+chi[dangqian+1].a3));
    if(p2==n/2) return max(dfs(dangqian+1,p1+1,p2,p3,res+chi[dangqian+1].a1),dfs(dangqian+1,p1,p2,p3+1,res+chi[dangqian+1].a3));
    if(p3==n/2) return max(dfs(dangqian+1,p1+1,p2,p3,res+chi[dangqian+1].a1),dfs(dangqian+1,p1,p2+1,p3,res+chi[dangqian+1].a2));
    return max(dfs(dangqian+1,p1+1,p2,p3,res+chi[dangqian+1].a1),max(dfs(dangqian+1,p1,p2+1,p3,res+chi[dangqian+1].a2),dfs(dangqian+1,p1,p2,p3+1,res+chi[dangqian+1].a3)));
}
ll dfs1(ll dangqian,ll p1,ll p2,ll res){
    //////cout<<dangqian<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<res<<"\n\n";
    if(dangqian>=n) return res;
    if(p1==n/2) return dfs1(dangqian+1,p1,p2+1,res+chi[dangqian+1].a2);
    if(p2==n/2) return dfs1(dangqian+1,p1+1,p2,res+chi[dangqian+1].a1);
    return max(dfs1(dangqian+1,p1,p2+1,res+chi[dangqian+1].a2),dfs1(dangqian+1,p1+1,p2,res+chi[dangqian+1].a1));
}
int main(){
    freopen("club.in","r",stdin);//
    freopen("club.out","w",stdout);//
    cin>>t;
    while(t--){
        ans=0;
        best1=0,best2=0,best3=0,a1equ0=1,a2equ0=1,a3equ0=1;
        cin>>n;
        if(n==2){
            cin>>chi[1].a1>>chi[1].a2>>chi[1].a3;
            cin>>chi[2].a1>>chi[2].a2>>chi[2].a3;
            ans=max(chi[1].a1+chi[2].a2,max(chi[1].a1+chi[2].a3,max(chi[1].a2+chi[2].a1,max(chi[1].a2+chi[2].a3,max(chi[1].a3+chi[2].a1,chi[1].a3+chi[2].a2)))));
            cout<<ans<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            cin>>chi[i].a1>>chi[i].a2>>chi[i].a3;
            if(chi[i].a1>chi[i].a2&&chi[i].a1>chi[i].a3){
                best1++;
                chi[i].best=1;
                if(chi[i].a2>chi[i].a3) chi[i].second=2,chi[i].last=3;
                else chi[i].second=3,chi[i].last=2;
            }
            else if(chi[i].a2>chi[i].a1&&chi[i].a2>chi[i].a3){
                best2++;
                chi[i].best=2;
                if(chi[i].a1>chi[i].a3) chi[i].second=1,chi[i].last=3;
                else chi[i].second=3,chi[i].last=1;
            }
            else {
                best3++;
                chi[i].best=3;
                if(chi[i].a2>chi[i].a1) chi[i].second=2,chi[i].last=1;
                else chi[i].second=1,chi[i].last=2;
            }
            if(chi[i].a1) a1equ0=0;
            if(chi[i].a2) a2equ0=0;
            if(chi[i].a3) a3equ0=0;
        }
        if(a2equ0&&a3equ0){
            sort(chi+1,chi+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=chi[i].a1;
            cout<<ans<<'\n';
            continue;
        }
        if(a1equ0&&a3equ0){
            sort(chi+1,chi+n+1,cmp1);
            for(int i=1;i<=n/2;i++) ans+=chi[i].a2;
            cout<<ans<<'\n';
            continue;
        }
        if(a1equ0&&a2equ0){
            sort(chi+1,chi+n+1,cmp2);
            for(int i=1;i<=n/2;i++) ans+=chi[i].a3;
            cout<<ans<<'\n';
            continue;
        }
        if(a3equ0){
            cout<<dfs1(0,0,0,0)<<'\n';
            continue;
        }
        cout<<dfs(0,0,0,0,0)<<'\n';
        /*if(a3equ0){
            if(best1>best2){
                sort(chi+1,chi+n+1,cmp1);
                for(int i=1;i<=n/2;i++) ans+=chi[i].a1;
                for(int i=n/2+1;i<=n;i++) ans+=chi[i].a2;
            }else{
                sort(chi+1,chi+n+1,cmp2);
                for(int i=1;i<=n/2;i++) ans+=chi[i].a2;
                for(int i=n/2+1;i<=n;i++) ans+=chi[i].a1;
            }
            cout<<ans<<'\n';
            continue;
        }*/
    }
    return 0;
}
