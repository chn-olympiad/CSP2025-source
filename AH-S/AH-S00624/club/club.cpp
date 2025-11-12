#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+5;
LL T,n,t,cnt[N],b[N],a[N][4],ans;
void dfs(LL cur,LL sum){
    if(cur==n+1){
        ans=max(ans,sum);
        return ;
    }
    if(cnt[1]<n/2){
        cnt[1]++;
        dfs(cur+1,sum+a[cur][1]);
        cnt[1]--;
    }
    if(cnt[2]<n/2){
        cnt[2]++;
        dfs(cur+1,sum+a[cur][2]);
        cnt[2]--;
    }
    if(cnt[3]<n/2){
        cnt[3]++;
        dfs(cur+1,sum+a[cur][3]);
        cnt[3]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        memset(b,0,sizeof b);
        memset(cnt,0,sizeof cnt);
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
        for(int i=1;i<=n;i++){
            b[i]=a[i][1];
            if(a[i][2]!=0||a[i][3]!=0) break;
            if(i==n){
                sort(b+1,b+n+1);
                reverse(b+1,b+n+1);
                for(int i=1;i<=n/2;i++) ans+=b[i];
            }
        }
        if(ans!=0){
            cout<<ans<<"\n";
            continue;
        }
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
