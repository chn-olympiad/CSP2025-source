#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int vis[5];
int a[N][5];
int ans,n;
void dfs(int step,int x){
    if (vis[1] > n/2 || vis[2] > n/2 || vis[3] > n/2) return;
    if (step > n) {
        ans = max(ans,x);
        return;
    }
    for (int i = 1;i <= 3;i++){
        vis[i]++;
        dfs(step + 1,x + a[step][i]);
        vis[i]--;
    }
}
struct node{
    int x,y,z;
}b[N];
bool cmp(node x,node y){
    return x.x + x.y + x.z > y.x + y.y + y.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        ans = 0;
        vis[1] = 0,vis[2] = 0,vis[3] = 0;
        cin>>n;
        for (int i = 1;i <= n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        if (n <= 30){
            dfs(0,0);
        }else{
            for (int i = 1;i <= n;i++){
                b[i].x = a[i][1];
                b[i].y = a[i][2];
                b[i].z = a[i][3];
            }
            sort(b+1,b+n+1,cmp);

            for (int i = 1;i <= n;i++){
                if (b[i].x >= b[i].y && b[i].x >= b[i].z){
                    if (vis[1] <= n/2 - 1){
                        ans += b[i].x;
                        vis[1]++;
                    }else{
                        if (b[i].y >= b[i].z){
                            ans += b[i].y;
                        }else{
                            ans += b[i].z;
                        }
                    }
                }else if (b[i].y >= b[i].x && b[i].y >= b[i].z){
                    if (vis[2] <= n/2 - 1){
                        ans += b[i].y;
                        vis[2]++;
                    }else{
                        if (b[i].x >= b[i].z){
                            ans += b[i].x;
                            vis[1]++;
                        }else{
                            ans += b[i].z;
                            vis[3]++;
                        }
                    }
                }else{
                    if (vis[3] <= n/2 - 1){
                        ans += b[i].z;
                        vis[3]++;
                    }else{
                        if (b[i].x >= b[i].y){
                            ans += b[i].x;
                            vis[1]++;
                        }else{
                            ans += b[i].y;
                            vis[2]++;
                        }
                    }
                }
            }
        }
        
        printf("%d\n",ans);
    }
    return 0;
}