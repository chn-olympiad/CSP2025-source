#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T;
int n;
struct node{
    int num,sum,id;
}a[3*N];
int k = 0;
bool f[N];
long long res = 0;
int nu[N][4];
void add(int num,int sum,int id){
    a[++k] = {num,sum,id};
}
bool cmp(node t1,node t2){
    return t1.sum>=t2.sum;
}
void dfs(int s,int x,int y,int z,long long ans){
    if(s==n+1){
        res = max(res,ans);
        return;
    }
    if(x<n/2)dfs(s+1,x+1,y,z,ans+nu[s][1]);
    if(y<n/2)dfs(s+1,x,y+1,z,ans+nu[s][2]);
    if(z<n/2)dfs(s+1,x,y,z+1,ans+nu[s][3]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(f,0,sizeof(f));
        int x,y,z;
        k = 0,res = 0;
        scanf("%d",&n);
        if(n==2){
            int u,v,w;
            scanf("%d%d%d",&x,&y,&z);
            scanf("%d%d%d",&u,&v,&w);
            res = max(max(max(x+v,x+w),max(y+u,y+w)),max(z+u,z+v));
            printf("%lld\n",res);
            continue;
        }else if(n<=20){
            for(int i = 1;i<=n;i++){
                scanf("%d%d%d",&nu[i][1],&nu[i][2],&nu[i][3]);
            }
            dfs(1,0,0,0,0);
            printf("%lld\n",res);
            continue;
        }
        for(int i = 1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            add(1,x,i),add(2,y,i),add(3,z,i);
        }
        sort(a+1,a+3*n+1,cmp);
        x = y = z = 0;
        for(int i = 1;i<=k;i++){
            if(f[a[i].id]==false&&x<n/2&&y<n/2&&z<n/2){
                res+=a[i].sum;
                f[a[i].id] = true;
                if(a[i].num==1)x++;
                else if(a[i].num==2)y++;
                else z++;
            }
        }
        printf("%lld\n",res);
    }



    return 0;
}

