#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,cnt;
struct edge{
    int a,b,c;
}e[100001];
struct node{
    int sc,id;
};
vector<node> cnta,cntb,cntc;
bool cmpa(node x,node y){
    if(abs(e[x.id].a-e[x.id].b)!=abs(e[y.id].a-e[y.id].b)){
        return abs(e[x.id].a-e[x.id].b)>abs(e[y.id].a-e[y.id].b);
    }
    if(abs(e[y.id].a-e[y.id].a)!=abs(e[y.id].a-e[y.id].a)){
        return abs(e[x.id].a-e[x.id].c)>abs(e[y.id].a-e[y.id].c);
    }
    return e[x.id].a>e[y.id].a;
}
bool cmpb(node x,node y){
    if(abs(e[x.id].a-e[x.id].b)!=abs(e[y.id].a-e[y.id].b)){
        return abs(e[x.id].a-e[x.id].b)>abs(e[y.id].a-e[y.id].b);
    }
    if(abs(e[y.id].b-e[y.id].c)!=abs(e[y.id].b-e[y.id].c)){
        return abs(e[x.id].b-e[x.id].c)>abs(e[y.id].b-e[y.id].c);
    }
    return e[x.id].b>e[y.id].b;
}
bool cmpc(node x,node y){
    if(abs(e[x.id].a-e[x.id].c)!=abs(e[y.id].a-e[y.id].c)){
        return abs(e[x.id].a-e[x.id].c)>abs(e[y.id].a-e[y.id].c);
    }
    if(abs(e[y.id].b-e[y.id].c)!=abs(e[y.id].b-e[y.id].c)){
        return abs(e[x.id].b-e[x.id].c)>abs(e[y.id].b-e[y.id].c);
    }
    return e[x.id].c>e[y.id].c;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        cnta.clear(),cntb.clear(),cntc.clear();
        for(int i=1;i<=n;i++){
            cin>>e[i].a>>e[i].b>>e[i].c;
            cnt=max({e[i].a,e[i].b,e[i].c});
            if(e[i].a==cnt){
                cnta.push_back({e[i].a,i});
            }else if(e[i].b==cnt){
                cntb.push_back({e[i].b,i});
            }else{
                cntc.push_back({e[i].c,i});
            }
        }
        sort(cnta.begin(),cnta.end(),cmpa);
        sort(cntb.begin(),cntb.end(),cmpb);
        sort(cntc.begin(),cntc.end(),cmpc);
        for(int i=0;i<cnta.size();i++){
            if(i<n/2){
                ans+=cnta[i].sc;
            }else{
                ans+=max(e[cnta[i].id].b,e[cnta[i].id].c);
            }
        }
        for(int i=0;i<cntb.size();i++){
            if(i<n/2){
                ans+=cntb[i].sc;
            }else{
                ans+=max(e[cntb[i].id].a,e[cntb[i].id].c);
            }
        }
        for(int i=0;i<cntc.size();i++){
            if(i<n/2){
                ans+=cntc[i].sc;
            }else{
                ans+=max(e[cntc[i].id].a,e[cntc[i].id].b);
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
