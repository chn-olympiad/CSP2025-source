#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long
using namespace std;
const int N=1e5+5;
int t;
int n;
struct node{
    int num;
    int id;
}a[N][3];
bool cmp(node x,node y){
    return x.num>y.num;
}
int cnt[3];
struct nodeq{
    int u;//di ji hang
    bool operator <(const nodeq&t)const{
        return a[u][0].num-a[u][1].num>a[t.u][0].num-a[t.u][1].num;
    }
};
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][0].num,&a[i][1].num,&a[i][2].num);
            a[i][0].id=0,a[i][1].id=1,a[i][2].id=2;
            sort(a[i],a[i]+3,cmp);
        }
        int ans=0;
        priority_queue<nodeq>q[3];
        for(int i=1;i<=n;i++){
            ans+=a[i][0].num;
           // printf("%d %d\n",a[i][0].id,a[i][0].num);
            cnt[a[i][0].id]++;
            q[a[i][0].id].push((nodeq){i});
        }
        if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
            printf("%d\n",ans);
            continue;
        }
        int maxn=max(cnt[0],max(cnt[1],cnt[2]));
        int maxid;
        if(maxn==cnt[0])maxid=0;
        else if(maxn==cnt[1])maxid=1;
        else maxid=2;
        int secid;
        for(int i=0;i<=2;i++){
            if(i==maxid)continue;
            for(int j=0;j<=2;j++){
                if(j==maxid)continue;
                if(j==i)continue;
                if(cnt[i]>=cnt[j]){
                    secid=i;
                }
            }
        }
        if(cnt[maxid]==n/2+1&&cnt[secid]==n/2){
            int u=q[maxid].top().u;
            if(a[u][1].id!=secid)break;
            ans-=a[u][0].num-a[u][1].num;
            u=q[secid].top().u;
            ans-=a[u][0].num-a[u][1].num;
            printf("%d\n",ans);
            continue;
        }
        while(q[maxid].size()>n/2){
            int u=q[maxid].top().u;
            q[maxid].pop();
            ans-=a[u][0].num-a[u][1].num;
        }
        printf("%d\n",ans);
    }
    return 0;
}
