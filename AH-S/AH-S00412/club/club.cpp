#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
int a[100010],b[100010],c[100010];
bool fa=1;
void dfs(long long s,int x,int y,int z,int i){
    if(x>n/2||y>n/2||z>n/2) return;
    if(i==n+1){
        ans=max(ans,s);
        return;
    }
    dfs(s+a[i],x+1,y,z,i+1);
    dfs(s+b[i],x,y+1,z,i+1);
    dfs(s+c[i],x,y,z+1,i+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(b[i]!=0||c[i]!=0) fa=0;
        }
        if(n<=30){
            dfs(0,0,0,0,1);
            printf("%d\n",ans);
        }else if(fa==0){
            sort(a+1,a+n+1);
            for(int i=n;i>=n/2+1;i--) ans+=a[i];
            printf("%d\n",ans);
        }
    }
    return 0;
}
