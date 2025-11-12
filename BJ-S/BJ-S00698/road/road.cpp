#include<bits/stdc++.h>
using namespace std;
int n,m,k,num,vis[100005];
long long ans=0;
struct node{
    int s,e,t;
}edge[100005];
void add(int s,int e,int t){
    edge[num].s=s;
    edge[num].e=e;
    edge[num].t=min(t,edge[num].t);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        edge[i].t=1e9+1;
    }
    for(int i=1;i<=m;i++){
        int s,e,l;
        cin>>s>>e>>l;
        ans+=l;
        ans-=2;
        add(s,e,l);
        add(e,s,l);
    }
    cout<<ans<<endl;
    return 0;
}
