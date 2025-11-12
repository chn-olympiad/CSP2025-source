#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,tong[4],rt;
long long ans;
struct node{
    long long v[4],x;
    int id;
}nodes[101010];
bool cmp(node a,node b){return a.x<b.x;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans = rt = tong[1] = tong[2] = tong[3] = 0;
        scanf("%d",&n);
        for(int i = 1;i<=n;i++){
            nodes[i].id = nodes[i].x = -1;
            long long maxn = -1;
            for(int j = 1;j<4;j++){
                scanf("%lld",&nodes[i].v[j]);
                if(nodes[i].v[j]>=maxn) nodes[i].id = j,nodes[i].x = maxn,maxn = nodes[i].v[j];
                else if(nodes[i].v[j]>nodes[i].x) nodes[i].x = nodes[i].v[j];
            }tong[nodes[i].id]++,ans += maxn;
            nodes[i].x = maxn-nodes[i].x;
        }for(int i = 1;i<=3;i++) if(tong[i]>n/2){rt = i;break;}
        sort(nodes+1,nodes+n+1,cmp);
        for(int i = 1;i<=n&&tong[rt]>n/2;i++){
            if(nodes[i].id!=rt) continue;
            ans -= nodes[i].x;
            tong[rt]--;
        }printf("%lld\n",ans);
    }
    return 0;
}
