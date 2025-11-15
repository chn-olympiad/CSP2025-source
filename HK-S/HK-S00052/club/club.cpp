#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int a[maxn][5];
int num[4];
int res;

void dfs(int i,int ans,int n){
    if(i==n*2+1){
        res=max(res,ans);
    }
    for(int j=1;j<=3;j++){
        if(num[j]==n)continue;
        num[j]++;
        dfs(i+1,ans+a[i][j],n);
        num[j]--;
    }
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;

    while(T--){
        int n;cin>>n;
        int m=n/2;
        for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
        for(int i=1;i<=3;i++)num[i]=0;
        res=0;
        dfs(1,0,m);
        cout<<res<<endl;
    }
    cout.flush();
    fclose(stdin);fclose(stdout);
}
