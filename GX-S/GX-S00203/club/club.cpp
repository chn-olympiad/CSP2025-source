#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],k[N],ans;
void dfs(int x,int sum){
    for(int i=1;i<=3;i++){
            if(k[i]==n/2){
                continue;
            }
        sum+=a[x][i];
        k[i]++;
        if(x<=n){
                if(k[i]==n/2){
                    dfs(x+1,sum);
                }else{
            dfs(x+1,sum);
            }
        }
        if(x==n){
        ans=max(ans,sum);
        }
        sum-=a[x][i];
        k[i]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
            ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
