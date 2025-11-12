#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,a[N][4],s,b[4],ans;

void dfs(int x){
    if(x==n+1){
        ans=max(s,ans);
        return;
    }
    for(int i=1;i<=3;i++){
        if(b[i]==n/2) continue;
        s+=a[x][i];
        b[i]++;
        dfs(x+1);
        s-=a[x][i];
        b[i]--;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        s=0,b[1]=0,b[2]=0,b[3]=0,ans=0;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
