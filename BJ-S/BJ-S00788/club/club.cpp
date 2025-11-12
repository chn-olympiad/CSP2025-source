#include <bits/stdc++.h>

using namespace std;
long long t,n,ans=-1;
long long a[200010][4];
void dfs(long long r,long long yi, long long er,long long sum){
    if (r==n){
        ans=max(ans,sum);
        return;
    }
    else{
        if (yi+1<=n/2){
            dfs(r+1,yi+1,er,sum+a[r+1][1]);
        }
        if (er+1<=n/2){
            dfs(r+1,yi,er+1,sum+a[r+1][2]);
        }
        if (r+1-yi-er<=n/2){
            dfs(r+1,yi,er,sum+a[r+1][3]);
        }
    }

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        ans=-1;
        for (int i=1;i<=n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        dfs(0,0,0,0);
        cout << ans;
    }
    return 0;
}
