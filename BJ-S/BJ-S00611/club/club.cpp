#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans;
struct club{
    int b[3];
}a[N];
struct node{
    int now,num,nxt;
    bool operator <(const node& node1) const{
        return node1.num<num;
    }
};
priority_queue<node>q[3];
bool cmp(club x,club y){
    int xm=max(x.b[0],max(x.b[1],x.b[2]));
    int ym=max(y.b[0],max(y.b[1],y.b[2]));
    return xm>ym;
}
void join(int id,int maxn,int nxt){
    int cha=a[id].b[maxn]-a[id].b[nxt];
    if(q[maxn].size()<n/2){
        q[maxn].push((node){a[id].b[maxn],cha,nxt});
    }else{
        if(cha<=q[maxn].top().num){
            q[nxt].push((node){a[id].b[nxt],100000,0});
        }else{
            node renew=q[maxn].top();
            q[maxn].pop();
            q[maxn].push((node){a[id].b[maxn],cha,nxt});
            q[renew.nxt].push((node){renew.now-renew.num,100000,0});
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].b[0]>>a[i].b[1]>>a[i].b[2];
            int minn=min(a[i].b[0],min(a[i].b[1],a[i].b[2]));
            a[i].b[0]-=minn;
            a[i].b[1]-=minn;
            a[i].b[2]-=minn;
            ans+=minn;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            int maxn=0,nxt=0;
            for(int j=1;j<3;j++){
                if(a[i].b[j]>a[i].b[maxn]){
                    maxn=j;
                }
            }
            for(int j=1;j<3;j++){
                if(j!=maxn&&a[i].b[j]!=0){
                    nxt=j;
                }
            }
            join(i,maxn,nxt);
        }
        for(int i=0;i<3;i++){
            while(!q[i].empty()){
                ans+=q[i].top().now;
                q[i].pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
