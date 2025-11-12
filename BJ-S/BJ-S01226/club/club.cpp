#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int mx(int a,int b){
    return a<b?b:a;
}
int mn(int a,int b){
    return a<b?a:b;
}

struct node{
    int a,b,d;
    bool operator<(node n){return d<n.d;}
}l[100005];

int a[100005][5],dp[205][205];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        int n,ans = 0;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }

        if(n <= 200){
            for(int i = 1; i <= n; i++){
                for(int j = mn(n/2,i); j >= 0; j--){
                    for(int k = mn(n/2,i); k >= 0; k--){
                        if(j+k > i) continue;
                        if(i-j-k > n/2) continue;

                        if(i-j-k<=0) dp[j][k] = 0;
                        if(j>0) dp[j][k] = mx(dp[j][k],dp[j-1][k]+a[i][0]);
                        if(k>0) dp[j][k] = mx(dp[j][k],dp[j][k-1]+a[i][1]);
                        if(i == n){
                            ans = mx(ans,dp[j][k]);
                        }
                    }
                }
            }
            cout << ans << endl;
        }
        else{
            for(int i = 1; i <= n; i++){
                l[i].a = a[i][0];
                l[i].b = a[i][1];
                l[i].d = a[i][0]-a[i][1];
                ans += l[i].a;
            }
            sort(l+1,l+n+1);
            for(int i = 1; i <= n/2; i++){
                ans -= l[i].d;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
