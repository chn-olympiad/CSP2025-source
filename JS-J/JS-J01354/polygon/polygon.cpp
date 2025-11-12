#include<bits/stdc++.h>
using namespace std;
#define please return
#define AC 0
int n,m,s[5005],ans;
void dfs(int sumnumber,int now,int maxlong,int sumlong){
    if(now==-1){
        if(sumnumber>=3&&sumlong>2*maxlong)ans++;
        ans=ans%998244353;
        return;
    }
    if(sumnumber+now+1<3)return;
    dfs(sumnumber+1,now-1,max(maxlong,s[now]),sumlong+s[now]);
    dfs(sumnumber,now-1,maxlong,sumlong);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s,s+n);
    dfs(0,n-1,0,0);
    cout<<ans;
    please AC;
}
