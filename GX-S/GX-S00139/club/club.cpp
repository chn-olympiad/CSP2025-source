#include<bits/stdc++.h>
using namespace std;

int t,n,a[3][0x3f3f3f],l[3];
bool vis[3][0x3f3f3f];

long long dfs(long long ma,int times){
    if(times>=n)return ma;
    else{
        long long tmp=ma;
        for(int i=0;i<3;i++){
            if( (l[i]>=(n>>1)) || vis[i][times]==1 )continue;
            vis[i][times]=1;
            l[i]++;
            ma=max(dfs(tmp+a[i][times],times+1),ma);
            vis[i][times]=0;
            l[i]--;
        }
    }
    return ma;
}

//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1

int main(){
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[0][i]>>a[1][i]>>a[2][i];
        }
        memset(vis,0,sizeof vis);memset(l,0,sizeof vis);
        cout<<dfs(0,0)<<"\n";
    }

    return 0;
}
