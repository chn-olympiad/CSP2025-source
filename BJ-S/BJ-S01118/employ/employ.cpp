#include<bits/stdc++.h>
using namespace std;
int a,b;
char c[100005];
int d[100005],p[100005],vis[100005],ans,m=998244353,sum,e[100005],j[100005];
void dfs(int now,int sum){
    if(sum>=b){
        ans+=j[a-now+1];
        if(ans>=m)ans-=m;
        return ;
    }
    if(now==a+1){
        return ;
    }
    for(int i=1;i<=a;i++){
        if(vis[i]==1)continue;
        int pl=0;
        if(c[now]=='1'&&now-1-sum<d[i])pl=1;
        vis[i]=1;
        p[now]=i;
        dfs(now+1,sum+pl);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    j[0]=1;
    for(int i=1;i<=a;i++){
        j[i]=j[i-1]*i;
        j[i]%=m;
    }
    scanf("%d %d",&a,&b);
    for(int i=1;i<=a;i++){
        scanf(" %c",&c[i]);
    }
    for(int i=1;i<=a;i++){
        scanf("%d",&d[i]);
    }
    if(a==b){
        for(int i=1;i<=a;i++){
            if(c[i]=='0'){
                printf("0");
                return 0;
            }
        }
        for(int i=1;i<=a;i++){
            if(d[i]==0){
                printf("0");
                return 0;
            }
        }
        ans=1;
        for(int i=1;i<=a;i++){
            ans=ans*i;
            ans%=m;
        }
        printf("%d",ans);
        return 0;
    }
    sort(d+1,d+a+1);
    dfs(1,0);
    printf("%d",ans);
    return 0;
}
