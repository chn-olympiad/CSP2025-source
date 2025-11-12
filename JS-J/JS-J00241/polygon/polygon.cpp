#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int mod=998244353;
int n,x[5005],ans,r[5005],cnt;
ull dfs(int m){
    ull tot=0,ans1=0;
    cnt++;
    r[cnt]=x[m];
    if(cnt>=3){
        for(int i=1;i<=cnt;i++){
            tot+=r[i];
        }
        if(tot>r[cnt]*2)   ans1++;
    }
    for(int i=m+1;i<=n;i++){
        ans1+=dfs(i)%mod;
        ans1%=mod;
    }
    r[cnt]=0;
    cnt--;
    return ans1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)   ans+=dfs(i);
    cout<<ans;
    return 0;
}
