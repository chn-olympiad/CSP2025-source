#include <bits/stdc++.h>
using namespace std;
int t;
#define ll long long

int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n==2){
            int a[4][4];
            for (int i=1;i<=n;i++){
                for (int j = 1;j<=3;j++){
                    cin >> a[i][j];
                }
            }
            int maxx=-1;
            if ((a[1][1]+a[2][2])>maxx) maxx=a[1][1]+a[2][2];
            if ((a[1][1]+a[2][3])>maxx) maxx=a[1][1]+a[2][3];
            if ((a[1][2]+a[2][1])>maxx) maxx=a[1][2]+a[2][1];
            if ((a[1][2]+a[2][3])>maxx) maxx=a[1][2]+a[2][3];
            if ((a[1][3]+a[2][1])>maxx) maxx=a[1][3]+a[2][1];
            if ((a[1][3]+a[2][2])>maxx) maxx=a[1][3]+a[2][2];
            cout << maxx << endl;
        }
        if (n==4){
            int a[5][4];
            int vis[4]={0};
            int maxx1=0;
            for (int i=1;i<=n;i++){
                int maxn=0,pos=0;
                for (int j = 1;j<=3;j++){
                    cin >> a[i][j];
                    if(maxn<a[i][j]){
                        maxn=a[i][j];
                        pos=j;
                    }
                }
                if(vis[pos]<=2){
                    vis[pos]++;
                    maxx1+=maxn;
                }
            }
            cout << maxx1 << endl;
        } else {
            ll v1[n+1]={0};
            ll v2[n+1]={0};
            ll v3[n+1]={0};
            ll ans=0,pos=0;
            ll vis[4]={0};
            for (ll i=1;i<=n;i++){
                ll x,y,z;cin >> x >> y >> z;
                v1[i]=x;
                v2[i]=y;
                v3[i]=z;
                ll k=max(x,max(y,z));
                if (k==x) pos=1;
                if (k==y) pos=2;
                if (k==z) pos=3;
                int temp[4]={0,x,y,z};
                if (vis[pos] <= n/2){
                    ans += k;
                    vis[pos]++;
                } else {
                    temp[pos]=0;
                    k=max(temp[1],max(temp[2],temp[3]));
                    if (k==x) pos=1;
                    if (k==y) pos=2;
                    if (k==z) pos=3;
                    if (vis[pos] <= n/2){
                        ans += k;
                        vis[pos]++;
                        temp[pos]=0;
                } else {
                    k=max(temp[1],max(temp[2],temp[3]));
                    if (k==x) pos=1;
                    if (k==y) pos=2;
                    if (k==z) pos=3;
                    if (vis[pos] <= n/2){
                        ans += k;
                        vis[pos]++;
                }
            }
            cout << ans << endl;
        }
    }

}

}
return 0;
}
