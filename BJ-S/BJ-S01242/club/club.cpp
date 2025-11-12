#include <bits/stdc++.h>
using namespace std;
int T;
int choose[100005];
int cnt[4];
int n=0,ans=0;
struct node{
    int a[4];
}A[100005];
bool cmp(node x,node y){
    return x.a[1]>y.a[1];
}
void dfs(int pos){
    if(pos==n+1){
        int res=0;
        for(int i = 1;i <= n;i++){
            res+=A[i].a[choose[i]];
        }
        if(res>ans)ans=res;
        return;
    }
    for(int i = 1;i <= 3;i++){
        if(cnt[i]+1<=n/2){
            cnt[i]++;
            choose[pos]=i;
            dfs(pos+1);
            cnt[i]--;
        }
    }
}
void dfsB(int pos){
    if(pos==n+1){
        int res=0;
        for(int i = 1;i <= n;i++){
            res+=A[i].a[choose[i]];
        }
        if(res>ans)ans=res;
        return;
    }
    for(int i = 1;i <= 2;i++){
        if(cnt[i]+1<=n/2){
            cnt[i]++;
            choose[pos]=i;
            dfsB(pos+1);
            cnt[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        bool visA=true,visB=true;
        ans=0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&A[i].a[1],&A[i].a[2],&A[i].a[3]);
            if(!(A[i].a[2]==A[i].a[3]&&A[i].a[2]==0)){
                visA=false;
            }
            if(A[i].a[3]!=0){
                visB=false;
            }
        }
        if(visA){
            sort(A+1,A+n+1,cmp);
            for(int i = 1;i <= n/2;i++){
                ans+=A[i].a[1];
            }
            printf("%d\n",ans);
            continue;
        }
        if(visB){
            dfsB(1);
            printf("%d\n",ans);
            continue;
        }
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
