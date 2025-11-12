#include <bits/stdc++.h>
using namespace std;
int dp[205][205][205];
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,q;

        cin >> n ;
        if(n==2){
            int a[5],b[5],c[5];
            cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
            int ans=-1;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    ans=max(ans,a[i]+b[j]);
                }
            }
            cout << ans<< endl;
        }else{
            int a[10005],b[10005],c[10005],s[10005];
            for(int i=1;i<=n;i++){
                cin >> a[i] >> b[i] >> c[i];
            }
            sort(a+1,a+n+1);
            cout << a[n]+a[n-1]<< endl;
        }
    }
    return 0;
}
