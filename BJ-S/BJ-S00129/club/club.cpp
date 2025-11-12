#include<bits/stdc++.h>
using namespace std;
int a[100010][10];
int cnt[10];
int ans,n;
void dfs(int t,int sum){
    if(t==n+1){
        ans=max(sum,ans);
        return;
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]+1<=n/2){
            cnt[i]++;
            dfs(t+1,sum+a[t][i]);
            cnt[i]--;
        }
    }
    return;
}
int main(){
    freopen("club2.in","r",stdin);
    freopen("club2.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ans=0,cnt[1]=0,cnt[2]=0,cnt[3]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
