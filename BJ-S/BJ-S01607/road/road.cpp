#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int fa[10100];
vector<pair<int,pair<int,int> > > te,e,ek[15];
int get(int a){
    if(fa[a]==a)return a;
    return fa[a]=get(fa[a]);
}
void uni(int a,int b){
    a=get(a),b=get(b);
    fa[a]=b;
}
int c[15],a[15][10100],ps[15];
int n,m,k;
inline int gt(int md){
    fr(i,1,n+k)fa[i]=i;
    int ct=0,res=0,ctt=0;
    vector<int> vc;
    vc.push_back(0);
    fr(i,1,k)if(md&(1<<(i-1)))ctt++,vc.push_back(i);
    fr(i,0,k)ps[i]=0;
    while(ct<n+ctt-1){
        int w=0x3f3f3f3f,x,u,v;
        for(auto t:vc){
            int ww=0x3f3f3f3f,xx,uu,vv;
            if(t==0&&ps[t]<n-1)ww=e[ps[t]].first,xx=0,uu=e[ps[t]].second.first,vv=e[ps[t]].second.second;
            else if(t!=0&&ps[t]<n)ww=ek[t][ps[t]].first,xx=t,uu=ek[t][ps[t]].second.first,vv=ek[t][ps[t]].second.second;
            if(ww<w)w=ww,x=xx,u=uu,v=vv;
        }
        if(get(u)!=get(v)){
            //if(md==1)cout << w << " " << u << " "<< v<< endl;
            uni(u,v);
            res+=w;
            ct++;
        }
        ps[x]++;
        if(x==0&&ps[x]==n-1)vc.erase(lower_bound(vc.begin(),vc.end(),x));
        else if(x!=0&&ps[x]==n)vc.erase(lower_bound(vc.begin(),vc.end(),x));
    }
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    fr(i,1,n+k)fa[i]=i;
    fr(i,1,m){
        int u,v,w;
        cin >> u >> v >> w;
        te.push_back({w,{u,v}});
    }
    sort(te.begin(),te.end());
    fr(i,1,k){
        cin >> c[i];
        fr(j,1,n){
            int w;cin >> w;
            ek[i].push_back({w,{n+i,j}});
        }
        sort(ek[i].begin(),ek[i].end());
    }
    int ans=0;
    for(auto x:te){
        int w=x.first,u=x.second.first,v=x.second.second;
        if(get(u)!=get(v)){
            ans+=w;
            uni(u,v);
            e.push_back({w,{u,v}});
        }
    }
    fr(i,1,(1<<k)-1){
        int res=0;
        fr(j,1,k)if(i&(1<<(j-1)))res+=c[j];
       // if(i==1)cout << res << endl;
        res+=gt(i);
        //if(i==1)cout << res << endl;
        ans=min(ans,res);
    }
    cout << ans << endl;
    return 0;
}
