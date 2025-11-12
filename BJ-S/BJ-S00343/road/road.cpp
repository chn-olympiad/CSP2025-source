#include<bits/stdc++.h>
using namespace std;
const int maxn=10005,maxm=1000005;
int k,head[maxn],cnt[maxn],n,m,cot=0,ans=0,c[maxm];
queue <int> q;
struct Node{
    int s,e,next,w,vis=0;
}a[maxm];
void add(int u,int v,int w){
    cot++;
    a[cot].s=u;
    a[cot].e=v;
    a[cot].w=w;
    a[cot].next=head[u];
    a[cot].vis=1;
    head[u]=cot;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(head,-1,sizeof head);
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        cnt[u]++;
        cnt[v]++;
        add(u,v,w);
        add(v,u,w);
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(cnt[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int s=q.front(),x=head[s];
            q.pop();
            cot--;
            ans+=a[x].w;
            cnt[a[x].s]--;
            cnt[a[x].e]--;
        }
        if(cot==0){
            cout<<ans;
            return 0;
        }
        return 0;
    }

    return 0;
}
