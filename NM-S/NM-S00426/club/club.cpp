#include<bits/stdc++.h>
using namespace std;
int t,b[100001],c[100001],f[1001][501];
int a[100001][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;++i)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        int ans = 0;
        if(n == 2){
            for(int i = 1;i <= n;++i)
                for(int j = 1;j <= n;++j)
                    if(i != j)
                        ans = max(ans,a[1][i] + a[2][j]);
        }else{
            for(int i = 1;i <= n;++i)
                b[i] = a[i][1];
            sort(b + 1,b + n + 1,greater<int>());
            for(int i = 1;i <= n / 2;++i)
                ans += b[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
