#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+10,M=2e4+10;
struct nn{
    int u,v;
    LL w;
}a[N],b[N];
int p[M];
int fd(int x){
    if(p[x]!=x){
        p[x]=fd(p[x]);
    }
    return p[x];
}
LL ans;
int n,m,k,l;
bool cmp(nn a,nn s){
    return a.w<s.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
        b[i]=a[i];
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            p[i]=i;
        }
        sort(a+1,a+1+m,cmp);
        for(int i=1;i<=m;i++){
            int u=a[i].u;
            int v=a[i].v;
            int fu=fd(u),fv=fd(v);
            if(fu!=fv){
                p[fu]=fv;
                ans+=a[i].w;
            }
        }
        cout<<ans;
        return 0;
    }
    int nl=n;
    l=m;
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        nl++;
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            b[++l]={nl,j,w};
        }
    }
    for(int i=1;i<=nl+10;i++){
        p[i]=i;
    }
    sort(b+1,b+1+l,cmp);
    for(int i=1;i<=l;i++){
        int u=b[i].u;
        int v=b[i].v;
        int fu=fd(u),fv=fd(v);
        if(fu!=fv){
            p[fu]=fv;
            ans+=b[i].w;
        }
    }
    cout<<ans;
    return 0;
}
