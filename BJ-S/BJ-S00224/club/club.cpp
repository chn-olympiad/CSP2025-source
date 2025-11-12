#include<bits/stdc++.h>
using namespace std;
struct Club{
    int ma,mb,mc;
}a[100005];
int n;
int dp[100005][5];
int ans;
int ca,cb,cc;
bool f;
bool cmp(Club X,Club Y){
    return X.ma<Y.ma;
}
void DFS(int x,int sum){
    if(x==n+1){
        ans=max(ans,sum);
        return;
    }
    if(ca<n/2){
        ca++;
        DFS(x+1,sum+a[x].ma);
        ca--;
    }
    if(cb<n/2){
        cb++;
        DFS(x+1,sum+a[x].mb);
        cb--;
    }
    if(cc<n/2){
        cc++;
        DFS(x+1,sum+a[x].mc);
        cc--;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        f=false;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].ma>>a[i].mb>>a[i].mc;
            if(a[i].mb!=0 || a[i].mc!=0) f=true;
        }
        if(n<=10){
            ans=ca=cb=cc=0;
            DFS(1,0);
            cout<<ans<<endl;
            continue;
        }
        else if(f==false){
            sort(a+1,a+1+n,cmp);
            int sum=0;
            for(int i=n;i>=n/2;i--) sum+=a[i].ma;
            cout<<sum<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].ma;
            dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].mb;
            dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].mc;
        }
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
    }
    return 0;
}
