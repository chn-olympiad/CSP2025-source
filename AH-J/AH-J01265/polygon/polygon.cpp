#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long mod=998244353ll,C[5005][5005],sumt;
int n,a[5005];
bool vis[5005],A=1;
long long dfs(int g,int h,int x,int s,int m){
    if(g==x+1){
        if(s>2*m) return 1;
        return 0;
    }
    long long cnt=0;
    for(int i=h+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            cnt+=(dfs(g+1,i,x,s+a[i],max(m,a[i]))%mod);
            cnt%=mod;
            vis[i]=false;
        }
    }
    return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) A=0;
    }
    if(n<=20){
        long long cnt=0;
        for(int i=3;i<=n;i++){
            cnt+=(dfs(1,0,i,0,0)%mod);
            cnt%=mod;
        }
        cout<<cnt;
    }else if(A){
        for(int i=3;i<=n;i++){
            for(int j=3;j<i;j++) C[i][j]=((C[i-1][j]*i)%mod)/(i-j);
            C[i][i]=1;
        }
        for(int i=3;i<=n;i++) sumt+=C[n][i],sumt%=mod;
        cout<<sumt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
