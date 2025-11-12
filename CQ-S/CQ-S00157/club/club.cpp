#include<bits/stdc++.h>
using namespace std;
const int N =1e5 + 10;
int t;
int n;
int a[5][N];
int mi[N], m;
long long h, ans;
int c[30] = {0,1,2,3,0,1,3,2,0,2,1,3,0,2,3,1,0,3,1,2,0,3,2,1};
bool f[N];
int d = 1;
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
        }
        for(int k = 1;k<=6;k++){
            for(int y = 1;y <= 3;y++){
                int i = c[y+d];
            m = 0, memset(mi,0,sizeof(mi));
            for(int j = 1;j <=n;j++){
                if(f[j])continue;
                if(m<=n/2){
                    h+=a[i][j];
                    f[j] = true;
                }
                else{
                    if(a[i][mi[m]]<a[i][j]){
                        f[j] = true;
                        f[mi[m]] = false;
                        h+=a[i][j]-mi[m];
                        int x = m - 1;
                        while(a[i][mi[x-1]]<=a[i][j]){
                            mi[x+1] = mi[x];
                            x--;
                        }
                        mi[x] = j;
                    }
                }
            }
        }
        ans = max(ans,h);
        d+=4;
        }
        printf("%lld", ans);
    }
    return 0;
}