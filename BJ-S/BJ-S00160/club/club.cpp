#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[1005][3];
ll mem[505][255][255];
//ll max(ll a,ll b){return a>b? a:b;}
ll dfs(int s,int s1,int s2){//s3=s-s1-s2
    if(s==n+1)return 0;
    if(mem[s][s1][s2])return mem[s][s1][s2];
    ll res=0;
    if(s1<n/2)res=max(res,dfs(s+1,s1+1,s2)+a[s][0]);
    if(s2<n/2)res=max(res,dfs(s+1,s1,s2+1)+a[s][1]);
    if(s-s1-s2-1<n/2)res=max(res,dfs(s+1,s1,s2)+a[s][2]);
    mem[s][s1][s2]=res;
    return res;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        memset(mem,0,sizeof(mem));
        printf("%d\n",dfs(1,0,0));
    }
    return 0;
}
