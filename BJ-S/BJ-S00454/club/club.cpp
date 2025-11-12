#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a,b,c;
}t[1000005];
struct nod{
    long long id,u,v,w;
    bool operator < (const nod &a)const{
        return a.w<w;
    }
}x,y;
long long T,n,m,ans,cnt[5],vis[1000005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        priority_queue<nod>pq;
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        for(long long i=1;i<=n;i++){
            scanf("%lld%lld%lld",&t[i].a,&t[i].b,&t[i].c);
            if(max({t[i].a,t[i].b,t[i].c})==t[i].a){
                ans+=t[i].a;
                pq.push({i,1,2,t[i].a-t[i].b});
                pq.push({i,1,3,t[i].a-t[i].c});
                cnt[1]++;
            }else
            if(max({t[i].a,t[i].b,t[i].c})==t[i].b){
                ans+=t[i].b;
                pq.push({i,2,1,t[i].b-t[i].a});
                pq.push({i,2,3,t[i].b-t[i].c});
                cnt[2]++;
            }else
            if(max({t[i].a,t[i].b,t[i].c})==t[i].c){
                ans+=t[i].c;
                pq.push({i,3,1,t[i].c-t[i].a});
                pq.push({i,3,2,t[i].c-t[i].b});
                cnt[3]++;
            }
        }
        while(!pq.empty()){
            nod now=pq.top();
            pq.pop();
            if(!vis[now.id]&&cnt[now.u]>(n/2)){
                cnt[now.u]--;
                cnt[now.v]++;
                ans-=now.w;
                vis[now.id]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
