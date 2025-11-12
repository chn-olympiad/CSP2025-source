#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct Node{
    int x,y,z;
}a[N];
struct tl{
    int c1,c2,c3,sum;
}s[N][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        }
        if(n == 2){
            int mx = 0;
            mx = max(mx,a[1].x + a[2].y);
            mx = max(mx,a[1].x + a[2].z);
            mx = max(mx,a[1].y + a[2].x);
            mx = max(mx,a[1].y + a[2].z);
            mx = max(mx,a[1].z + a[2].x);
            mx = max(mx,a[1].z + a[2].y);
            printf("%d\n",mx);
        }else{
            s[1][1].sum = a[1].x;
            s[1][2].sum = a[1].y;
            s[1][3].sum = a[1].z;
            int ans = 0;
            for(int i=2;i<=n;i++){
                for(int j=1;j<=3;j++){
                    int newc1,newc2,newc3;
                    newc1 = newc2 = newc3 = 0;
                    if(s[i-1][j].c1 + 1 <= n / 2){
                        newc1 = s[i-1][j].sum + a[i].x;
                    }
                    if(s[i-1][j].c2 + 1 <= n / 2){
                        newc2 = s[i-1][j].sum + a[i].y;
                    }
                    if(s[i-1][j].c3 + 1 <= n / 2){
                        newc3 = s[i-1][j].sum + a[i].z;
                    }
                    if(newc1 > newc2 && newc1 > newc3){
                        s[i][j].c1 = s[i-1][j].c1 + 1;
                        s[i][j].sum = newc1;
                    }else if(newc2 > newc1 && newc2 > newc3){
                        s[i][j].c2 = s[i-1][j].c2 + 1;
                        s[i][j].sum = newc2;
                    }else{
                        s[i][j].c3 = s[i-1][j].c3 + 1;
                        s[i][j].sum = newc3;
                    }
                    ans = max(ans,s[i][j].sum);
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
