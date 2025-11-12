#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int t,a[N][5],d[N],dd[N],ddd[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        int n;
        long long ans = 0;
        cin >> n;
        int pon = n/2;
        memset(a,0,sizeof(a));
        for(int i = 1;i<=n;i++){
            for(int j = 1; j<=3;j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1;i<=n;i++) d[i] = a[i][1];
        sort(d+1,d+1+n,cmp);
        for(int i = 1;i<=pon;i++){
            ans += d[i];
        }
        cout << ans << endl;

    }

    return 0;
}
