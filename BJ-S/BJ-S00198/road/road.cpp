#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,f[N];
struct T{
    int u,v,w;
    bool operator<(const T&p)const{
        return w<p.w;
    }
}t[M];
int find(int x){
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}
bool marge(int u,int v){
    int bu=find(u),bv=find(v);
    if(bu==bv)return false;
    f[bu]=bv;
    return true;
}
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)f[i]=i;
    if(k==0){
        for(int i=1;i<=m;i++)cin>>t[i].u>>t[i].v>>t[i].w;
        sort(t+1,t+1+m);
        int ans=0;
        for(int i=1;i<=m;i++){
            if(marge(t[i].u,t[i].v)){
                ans+=t[i].w;
            }
        }
        cout<<ans;
    }else cout<<0;
    return 0;
}