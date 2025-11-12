#include<bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;i++)
using namespace std;
int t,n,a[100005][5],c[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cnt=0;
        priority_queue<pair<int,int> >q[4];
        rep(i,1,n){
            int minn=1e8;
            rep(j,1,3){
                scanf("%d",&a[i][j]);
                minn=min(minn,a[i][j]);
            }
            int c=0,g[5];
            rep(j,1,3){
                if(!c&&a[i][j]==minn){
                    c=1;
                    a[i][j]=0;
                    g[j]=1;
                }
                else g[j]=0;
            }
            minn=1e8;
            rep(j,1,3){
                if(!g[j]){
                    minn=min(minn,a[i][j]);
                }
            }
            rep(j,1,3){
                if(!g[j])a[i][j]-=minn;
            }
            cnt+=minn;
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                q[1].push({a[i][1],i});
            }
            if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                q[2].push({a[i][2],i});
            }
            if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
                q[3].push({a[i][3],i});
            }
        }
        if(q[1].size()>q[2].size()&&q[1].size()>q[3].size()){
            c[1]=1;
            if(q[2].size()>q[3].size()){
                c[2]=2;
                c[3]=3;
            }
            else{
                c[2]=3;
                c[3]=2;
            }
        }
        if(q[2].size()>q[1].size()&&q[2].size()>q[3].size()){
            c[1]=2;
            if(q[1].size()>q[3].size()){
                c[2]=1;
                c[3]=3;
            }
            else{
                c[2]=3;
                c[3]=1;
            }
        }
        if(q[3].size()>q[2].size()&&q[3].size()>q[1].size()){
            c[1]=3;
            if(q[2].size()>q[1].size()){
                c[2]=2;
                c[3]=1;
            }
            else{
                c[2]=1;
                c[3]=2;
            }
        }
        for(int rp=1;rp<=3;rp++){
            int i=c[rp];
            for(int j=1;j<=n/2&&!q[i].empty();j++){
                cnt+=q[i].top().first;
                q[i].pop();
            }
            while(!q[i].empty()){
                if(a[q[i].top().second][c[rp+1]]>a[q[i].top().second][c[rp+2]]){
                    q[c[rp+1]].push({a[q[i].top().second][c[rp+1]],q[i].top().second});
                }
                else{
                    q[c[rp+2]].push({a[q[i].top().second][c[rp+2]],q[i].top().second});
                }
                q[i].pop();
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
