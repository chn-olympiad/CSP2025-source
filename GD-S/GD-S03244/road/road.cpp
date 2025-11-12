#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m,k;
int c[13];
int a[13][maxn];
struct cedge{
    int u,v,w,num;
    friend bool operator<(cedge A,cedge B){
        return A.w>B.w;
    }
};
priority_queue<cedge> cque[2];
unsigned long long ans=0;
struct edge{
    int u,v,w;
    friend bool operator<(edge A,edge B){
        return A.w>B.w;
    }
};
int dis[maxn];
int find(int o){
    if(o==dis[o]){
        return o;
    }
    else{ 
        return dis[o]=find(dis[o]);
    }
}
priority_queue<edge> que;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        dis[i]=i;
    }
    for(int i=0,u,v,w;i<m;i++){
        cin>>u>>v>>w;
        que.push({u,v,w});
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            for(int q=1;q<j;q++){
                cque[0].push({q,j,c[i]+a[i][j]+a[i][q],i});
                cque[1].push({q,j,a[i][j]+a[i][q],i});
            }
        }
    }

    int cnt=n-1;
    while (cnt)
    {
        edge top=que.top();
        int u=top.u,v=top.v,w=top.w,p;
        if(find(u)==find(v)){
            continue;
        }
        bool flag=false;
        while (!cque[0].empty())
        {
            cedge ctop=cque[0].top();
            if(ctop.w>=w)break;
            if(a[ctop.num]==0){
                cque[0].pop();
                continue;
            }
            if(find(ctop.u)!=find(ctop.v)){
                flag=true;
                u=ctop.u,v=ctop.v,w=ctop.w,p=ctop.num;
                cque[0].pop();
                break;
            }else{
                cque[0].pop();
            }
        }
        while (!cque[1].empty()&&!flag)
        {
            cedge ctop=cque[1].top();
            if(ctop.w>=w)break;
            if(a[ctop.num]!=0){
                break;
            }
            if(find(ctop.u)!=find(ctop.v)){
                flag=true;
                u=ctop.u,v=ctop.v,w=ctop.w,p=ctop.num;
                cque[1].pop();
                break;
            }else{
                cque[1].pop();
            }
        }
        
        if(flag){
            ans+=w;
            c[p]=0;
        }else{
            ans+=w;
            que.pop();
        }
        cnt--;
        dis[find(u)]=find(v);
    }
    cout<<ans;
}