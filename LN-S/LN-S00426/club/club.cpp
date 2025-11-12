#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int t,n;
struct xz{
    int a;
    int d;
};
struct cy{
    xz a[5];
    int hlz;
    cy(){
        a[1].d=1;
        a[2].d=2;
        a[3].d=3;
    }
    friend bool operator < (cy a,cy b){
        return a.hlz<b.hlz;
    }
}cys[100005];
bool cmp1(xz a,xz b){
    return a.a>b.a;
}
bool cmp2(cy a,cy b){
    return a.a[1].a>b.a[1].a;
}
bool cmp3(xz a,xz b){
    return a.d<b.d;
}
int ans;
priority_queue<cy> pq[5];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&cys[i].a[1].a,&cys[i].a[2].a,&cys[i].a[3].a);
            sort(cys[i].a+1,cys[i].a+4,cmp1);
            cys[i].hlz=cys[i].a[2].a-cys[i].a[1].a;
        }
        sort(cys+1,cys+n+1,cmp2);
        for(int i=1;i<=n;i++){
            //printf("i:%d d:%d siz:%d\n",i,cys[i].a[1].d,pq[cys[i].a[1].d].size());
            if((int)(pq[cys[i].a[1].d].size())==n/2){
                cy tmp=pq[cys[i].a[1].d].top();
                if(tmp.hlz>cys[i].hlz){
                    //printf("111\n");
                    pq[cys[i].a[1].d].pop();
                    ans-=tmp.a[1].a;
                    ans+=tmp.a[2].a;
                    pq[tmp.a[2].d].push(tmp);
                    pq[cys[i].a[1].d].push(cys[i]);
                    ans+=cys[i].a[1].a;
                }
                else{
                    //printf("222\n");
                    pq[cys[i].a[2].d].push(cys[i]);
                    ans+=cys[i].a[2].a;
                }
            }
            else{
                //printf("333\n");
                ans+=cys[i].a[1].a;
                pq[cys[i].a[1].d].push(cys[i]);
            }
        }
        printf("%d\n",ans);
        while(!pq[1].empty()){
            pq[1].pop();
        }
        while(!pq[2].empty()){
            pq[2].pop();
        }
        while(!pq[3].empty()){
            pq[3].pop();
        }
        ans=0;
        for(int i=1;i<=n;i++){
            sort(cys[i].a+1,cys[i].a+4,cmp3);
        }
        //shu zu qing kong
    }
    return 0;
}