#include<bits/stdc++.h>
using namespace std;

int T,n,a[100005][5];
int f[100005][5];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
            scanf("%d",&n);
        for(int i = 1;i <= n;i++){
                for(int j = 1;j <= 3;j++){
                    f[i][j] = 0;
                }
        }
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        }
        int aa = 0,bb = 0,cc= 0;
        for(int i = 2;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                if(aa <= n / 2 && bb <= n / 2 && cc <= n / 2){
                    f[i][j] = max(f[i - 1][j] + a[i][j],f[i][j]);
                    if(j == 1){
                        aa++;
                    }else{
                        if(j == 2){
                            bb++;
                        }else{
                            cc++;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= 3;i++){
            ans = max(ans,f[n][i]);
        }
        printf("%d",ans);
    }
    return 0;
}
