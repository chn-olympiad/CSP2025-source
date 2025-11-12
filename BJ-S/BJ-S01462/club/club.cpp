#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10][100010],e[10],maxn=-1,ans=0;
bool ifa,ifb;
void dfs(long long cnt,long long sum){
    if(cnt==n+1){
        maxn=max(maxn,sum);
    }

    for(int i=1;i<=3;i++){
        if(!((e[i]+1)*2>n)){
            e[i]++;
            dfs(cnt+1,sum+a[i][cnt]);
            e[i]--;
        }

    }
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxn=-1;
        ans=0;
        memset(a,0,sizeof(a));
        memset(e,0,sizeof(e));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            if(a[2][i]!=0||a[3][i]!=0)ifa=1;
            if(a[3][i]!=0)ifb=1;
        }
        if(!ifa){
            sort(a[1]+1,a[1]+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[1][i];
            }
            cout<<ans<<'\n';
            continue;
        }
        dfs(1,0);
        cout<<maxn<<'\n';
    }
    return 0;
}
