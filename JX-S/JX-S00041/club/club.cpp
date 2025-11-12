#include<iostream>
#include<algorithm>
using namespace std;
const int M = 1e5 + 10;
struct node{
    int a[4];
    int id[4];
    node(){}
    node(int x1,int x2,int x3){
        a[1] = x1,a[2] = x2,a[3] = x3;
        id[1] = 1,id[2] = 2,id[3] = 3;
        if(a[id[1]]<a[id[2]]) swap(id[1],id[2]);
        if(a[id[1]]<a[id[3]]) swap(id[1],id[3]);
        if(a[id[2]]<a[id[3]]) swap(id[2],id[3]);
    }
    bool operator < (const node &x) const{
        return a[id[2]]-a[id[1]]<x.a[x.id[2]]-x.a[x.id[1]];
    }
}p[M];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int a,b,c;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a,&b,&c);
            p[i] = node(a,b,c);
        }
        sort(p+1,p+1+n);
        int cnt[4] = {};
        long long ans = 0;
        for(int i=1;i<=n;i++){
            if(cnt[p[i].id[1]]<n/2){
                ans += p[i].a[p[i].id[1]];
                cnt[p[i].id[1]]++;
            }else{
                ans += p[i].a[p[i].id[2]];
                cnt[p[i].id[2]]++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
