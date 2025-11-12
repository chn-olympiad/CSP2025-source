#include <bits/stdc++.h>
using namespace std;
int t,n,a[4][100005],ans,sum,s1,s2,s3;
bool cmp(int a,int b){
    return a>b;
}
void dfs(int x){
    if (x>n){
        ans=max(ans,sum);
    }
    if (s1+1<=n/2){
        s1++;
        sum+=a[1][x];
        dfs(x+1);
        sum-=a[1][x];
        s1--;
    }
    if (s2+1<=n/2){
        s2++;
        sum+=a[2][x];
        dfs(x+1);
        sum-=a[2][x];
        s2--;
    }
    if (s3+1<=n/2){
        s3++;
        sum+=a[3][x];
        dfs(x+1);
        sum-=a[3][x];
        s3--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        memset(a[1],0,sizeof(a[1]));
        memset(a[2],0,sizeof(a[2]));
        memset(a[3],0,sizeof(a[3]));
        ans=0;
        cin >> n;
        int fx=1,fy=1;
        for (int i=1;i<=n;i++){
            cin >> a[1][i] >> a[2][i] >> a[3][i];
            if (a[2][i]>0&&a[3][i]==0) fy=0;
            if (a[3][i]>0) fx=fy=0;
        }
        if (fy){
            sort(a[1]+1,a[1]+n+1,cmp);
            for (int i=1;i<=n/2;i++){
                ans+=a[1][i];
            }
            cout << ans << "\n";
            continue;
        }
        if (fx){
            continue;
        }
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}
