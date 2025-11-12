#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
long long sum[N];
int ans=0;
long long n,k;
void dfs(int e,int cnt){
    ans=max(cnt,ans);
    if(e==n) return ;
    for(int i=e+1;i<=n;i++){
        int c=0;
        c=sum[i]^sum[e];
        if(c==k){
            dfs(i,cnt+1);
        }
    }
    return ;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1) sum[i]=a[i];
        else sum[i]=(sum[i-1]^a[i]);
    }
    dfs(0,0);
    printf("%d",ans);
    return 0;
}
