#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,g1[MAXN],g2[MAXN],g3[MAXN],id[4],m,ans;
int dp[MAXN][4];
void dfs(int u,int sum){
        if(u>n){
            ans=max(ans,sum);
            return;
        }

    for(int i=1;i<=3;i++){
        if(id[i]>=m)continue;
        id[i]++;

        if(i==1)
            dfs(u+1,sum+g1[u]);
        else if(i==2)
            dfs(u+1,sum+g2[u]);
        else
            dfs(u+1,sum+g3[u]);
        id[i]--;
    }
    return;

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        bool flag3=true,flag2=true,flag1=true;
        memset(dp,0,sizeof(dp));
        memset(id,0,sizeof(id));
        ans=0;

        cin>>n;
        m=n/2;
        for(int i=1;i<=n;i++){

            cin>>g1[i]>>g2[i]>>g3[i];
            if(g2[i]!=0)flag2=false;
            if(g3[i]!=0)flag3=false;
            if(g1[i]!=0)flag1=false;
        }
        if(flag2=true&&flag1==true){
            sort(g3+1,g3+n+1);
            for(int i=n;i>n/2;i--)
                ans+=g3[i];
            cout<<ans<<endl;
            continue;
        }
        if(flag2=true&&flag3==true){
            sort(g1+1,g1+n+1);
            for(int i=n;i>n/2;i--)
                ans+=g1[i];
            cout<<ans<<endl;
            continue;
        }

        dfs(1,0);
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
