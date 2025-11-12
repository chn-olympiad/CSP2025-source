#include<bits/stdc++.h>
using namespace std;
int fa[10100];
int ff(int n){
    if(n==fa[n])return n;
    fa[n]=ff(fa[n]);
    return fa[n];
}
bool lt(int a,int b){
    if(ff(a)==ff(b))return true;
    return false;
}
void hb(int a,int b){
    fa[ff(a)]=ff(fa[b]);
}
struct roa{
    int s,e,m;//start end money
};
bool cmp(roa a,roa b){
    return a.m<b.m;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    int oi=0;
    roa ac[m+1];
    for(int i=1;i<=m;i++){
        int st,en,mo;
        cin>>st>>en>>mo;
        ac[i].s=st;ac[i].e=en;ac[i].m=mo;
    }
    sort(ac+1,ac+m+1,cmp);
    for(int i=1;i<=m;i++){
        int st=ac[i].s,en=ac[i].e,mo=ac[i].m;
        if(lt(st,en))continue;
        oi+=mo;
        hb(st,en);
    }
    if(k==0){
        cout<<oi;
        return 0;
    }
    for(int ii=1;ii<=k;ii++){
        int c;cin>>c;
        int kij;
        bool al0=true;
        if(c!=0)al0=false;
        for(int i=1;i<=n;i++){
            cin>>kij;
            if(kij!=0&&al0)al0=false;
        }
        if(al0){
            cout<<0;
            return 0;
        }
    }
    return 0;
}
