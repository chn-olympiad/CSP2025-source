#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define  fr first
#define sc second
const int N=1e5+10;
int T,n,ans,a[N][5],cnt[5];
priority_queue<int>q[5];
inline void init(){
    ans=0;
    for(int i=1;i<=3;i++){
        cnt[i]=0;
        while(!q[i].empty())q[i].pop();
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
            }
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                q[1].push(max(a[i][2],a[i][3])-a[i][1]);
                cnt[1]++;ans+=a[i][1];
            }
            else{
                if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                    q[2].push(max(a[i][1],a[i][3])-a[i][2]);
                    cnt[2]++;ans+=a[i][2];
                }
                else{
                    q[3].push(max(a[i][1],a[i][2])-a[i][3]);
                    cnt[3]++;ans+=a[i][3];
                }
            }
        }
        for(int i=1;i<=3;i++){
            while(cnt[i]>n/2){
                ans+=q[i].top();q[i].pop();
                cnt[i]--;
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}