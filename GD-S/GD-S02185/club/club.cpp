#include<bits/stdc++.h>
using namespace std;
namespace SOLVE{
#define ll long long
#define N 100000
struct node{
    int id,p,val;
    // bool operator < (const struct node &b) const{return val>b.val;}
    // bool operator > (const struct node &b) const{return val<b.val;}
};
inline bool cmpID(node &a,node &b){return a.p<b.p||a.p==b.p&&a.id<b.id;}
inline bool cmpVAL(node &a,node &b){return a.val>b.val;}
int n,vis[N+1];
node a[N*3+1];
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        vis[i]=0;
        scanf("%d%d%d",&a[i].val,&a[i+n].val,&a[i+2*n].val);
        a[i].id=a[i+n].id=a[i+2*n].id=i;
        a[i].p=1,a[i+n].p=2,a[i+2*n].p=3;
    }
    sort(a+1,a+1+3*n,cmpVAL);
    ll ans=0;
    int cnt[4]={0,0,0,0};
    for(int i=1;i<=3*n;++i){
        int id=a[i].id,val=a[i].val;
        if(vis[id])continue;
        ans+=val;
        vis[id]=a[i].p;
        ++cnt[a[i].p];
    }
    int q=0;
    for(int i=1;i<=3;++i)if(cnt[i]>n/2)q=i;
    if(q){
        sort(a+1,a+1+3*n,cmpID);
        priority_queue<int> pq;
        for(int i=1;i<=n;++i){
            if(vis[i]==q){
                int A,B=-1;
                for(int j=0;j<3;++j){
                    if(a[i+j*n].p==q)A=a[i+j*n].val;
                    else B=max(B,a[i+j*n].val);
                }
                pq.push(B-A);
            }
        }
        for(int i=1;i<=cnt[q]-n/2;++i)ans+=pq.top(),pq.pop();
    }
    printf("%lld\n",ans);
}
void main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)work();
}
}
int main(){SOLVE::main();return 0;}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/