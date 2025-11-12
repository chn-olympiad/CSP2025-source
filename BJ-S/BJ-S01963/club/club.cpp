#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,maxn,ans,sum;
int a[N][5],cnt[5];
struct node{
    int x,y,v;
}b[N];
bool vis[N];
void dfs(int x,int sum){
    if(x>n){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(cnt[i]<maxn){
            cnt[i]++;
            dfs(x+1,sum+a[x][i]);
            cnt[i]--;
        }
    }
}
bool cmp(node p,node q){
    return p.v>q.v;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        maxn=n/2;
        int tot=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            for(int j=1;j<=3;j++)
            {
                b[++tot].x=i;
                b[tot].y=j;
                b[tot].v=a[i][j];
            }
        }
        memset(cnt,0,sizeof(cnt));
        if(n<=10){
            ans=-1;
            dfs(1,0);
        }
        else{
        sort(b+1,b+tot+1,cmp);
        ans=0,sum=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=tot;i++)
        {
            if(cnt[b[i].y]<maxn&&!vis[b[i].x]){
                vis[b[i].x]=1;
                sum++;
                ans+=b[i].v;
                cnt[b[i].y]++;
            }
            if(sum>=n)
                break;
        }

        }
        printf("%d\n",ans);
    }

    return 0;
}

