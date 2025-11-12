#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int k;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>k;
    for(int p=1;p<=k;p++){
    int n;
    cin>>n;
    int f[N][N];
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++) cin>>f[i][j];
    }
    int ans=0;
    ans=max(ans,(f[1][1]+f[2][1]));
    ans=max(ans,(f[1][1]+f[2][2]));
    ans=max(ans,(f[1][1]+f[2][3]));
    ans=max(ans,(f[1][2]+f[2][1]));
    ans=max(ans,(f[1][2]+f[2][2]));
    ans=max(ans,(f[1][2]+f[2][3]));
    ans=max(ans,(f[1][3]+f[2][1]));
    ans=max(ans,(f[1][3]+f[2][2]));
    ans=max(ans,(f[1][3]+f[2][3]));
    cout<<ans<<endl;
    }
}