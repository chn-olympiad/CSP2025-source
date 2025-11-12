#include<bits/stdc++.h>
using namespace std;
int t;
int a[100010][5];
int ans;
int n;
int vis[5];
void f(int x,int w){
    if(x == n+1){
        ans = max(ans,w);
        return;
    }
    for(int i = 1;i<=3;i++){
        if(vis[i]<n/2){
            w+=a[x][i];
            vis[i]++;
            f(x+1,w);
            w-=a[x][i];
            vis[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    int h = 1;
    while(t--){
        ans = 0;
        scanf("%d",&n);
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=3;j++){
                scanf("%d",&a[i][j]);
                if(j == 2 && i>1){
                    if(a[i][j]!=a[i-1][j]) h = 0;
                }else if(j == 3){
                    if(a[i][j]!=0) h = 0;
                }
            }
        }
        if(h == 0) f(1,0);
        else{
            int c = 1;
            int maxx = -1;
            int k;
            while(true){
                maxx = -1;
                for(int i = 1;i<=n;i++){
                    if(a[i][1]>maxx){
                        maxx = a[i][1];
                        k = i;
                    }
                }
                if(maxx>=a[1][2] && c<=n/2){
                    ans+=maxx;
                    c++;
                    a[k][1] = -1;
                }else{
                    break;
                }
            }
            if(n-(c-1)>n/2){
                ans+=(n-(c-1))*a[1][2];
            }else{
                ans+=(n/2)*a[1][2];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
