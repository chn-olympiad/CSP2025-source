#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,cnt,a[5005],c[5005];
map<pair<int,pair<int,int>>,int>mp;
void dfs(int x,int h,int m,int ma){
    pair<int,int>q;
    q.first=m,q.second=ma;
    pair<int,pair<int,int>>r;
    r.first=h,r.second=q;
    if(m>=3&&h>ma*2)
        if(mp[r]==0)
        {cnt=(cnt+1)%mod;mp[r]=1;}
    if(x>n) return;
    dfs(x+1,h+a[x],m+1,max(a[x],ma));
    dfs(x+1,h,m,ma);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=0;
    }
    if(flag==0){
        dfs(1,0,0,0);
        cout<<cnt;
    }else if(flag==1){
        c[3]=1;
        for(int i=4;i<=n;i++){
            c[i]=c[i-1]+(i-1)*(i-2)/2;
        }
        cout<<c[n]%mod;
    }
}
/*
ccfmeiyou8==D
*/
