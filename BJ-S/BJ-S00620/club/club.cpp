#include<bits/stdc++.h>
using namespace std;

long long t,n,ans,a[200005][5];
long long x,y,z;

void dfs(long long l,long long k){
    if(l==n){
        ans=max(ans,k);
        return ;
    }
    if(x<n/2){
        x++;
        dfs(l+1,k+a[l+1][1]);
        x--;
    }if(y<n/2){
        y++;
        dfs(l+1,k+a[l+1][2]);
        y--;
    }if(z<n/2){
        z++;
        dfs(l+1,k+a[l+1][3]);
        z--;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(long long i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        x=y=z=0;
        dfs(0,0);
        cout<<ans<<"\n";
    }

    return 0;
}
