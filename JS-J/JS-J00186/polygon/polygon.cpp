#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int p=998244353;
int n,a[5001],ans,b[5001],mx=0;
void dfs(int i,int p){
    if(i==p){
        int tot=0,la=0,cnt;
        for(int j=1;j<=p;j++){
            if(b[j]!=0){
                tot+=a[j];
                la=max(la,a[j]);
                cnt++;
            }
        }
        if(tot>2*la&&cnt>2){
            ans++;
            ans%=p;
        }
        return;
    }
    b[i]=0;
    dfs(i+1,p);
    b[i]=1;
    dfs(i+1,p);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
    }
    if(n==3){
        int t=a[1]+a[2]+a[3];
        int mg=max(max(a[1],a[2]),a[3]);
        if(2*mg<t){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else{
        dfs(1,n);
        cout<<ans;
    }
    return 0;
}
