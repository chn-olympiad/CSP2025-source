#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100010][4],b[100010],dp[100010][4];
ll ans;
bool vis[100010];
void dfs1(int cur1,int cur2,ll sum1,ll sum2){
    if(cur1+cur2==n){
        ans=max(ans,sum1+sum2);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            if(cur1<n/2)dfs1(cur1+1,cur2,sum1+a[i][1],sum2);
            if(cur2<n/2)dfs1(cur1,cur2+1,sum1,sum2+a[i][2]);
            vis[i]=false;
        }
    }
}
void dfs2(int cur1,int cur2,int cur3,ll sum1,ll sum2,ll sum3){
    if(cur1+cur2+cur3==n){
        ans=max(ans,sum1+sum2+sum3);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            if(cur1<n/2)dfs2(cur1+1,cur2,cur3,sum1+a[i][1],sum2,sum3);
            if(cur2<n/2)dfs2(cur1,cur2+1,cur3,sum1,sum2+a[i][2],sum3);
            if(cur3<n/2)dfs2(cur1,cur2,cur3+1,sum1,sum2,sum3+a[i][3]);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(b,0,sizeof(b));
        ans=0;
        cin>>n;
        int f=0,f1=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]==0&&a[i][3]==0&&f==0)b[i]=a[i][1];
            else f=1;
            if(a[i][3]!=0)f1=1;
        }
        if(f==0){
            sort(b+1,b+1+n);
            for(int i=n;i>n/2;i--)ans+=b[i];
            cout<<ans<<endl;
        }
        else if(f1==0){
            dfs1(0,0,0,0);
            cout<<ans<<endl;
        }
        else{
			if(n<=6){
				dfs2(0,0,0,0,0,0);
				cout<<ans<<endl;
			}
            else{
				dfs2(0,0,0,0,0,0);
				cout<<ans<<endl;
			}
       }
    }
    return 0;
}
