#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int T,n;
int a[MAXN][3],chos[MAXN];
int cnt[MAXN];

inline int mid(int a,int b,int c){
    return a + b + c - max({a,b,c}) - min({a,b,c});
}

int main(){
    #ifndef kevin
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    #endif
    scanf("%d",&T);
    while (T --){
        scanf("%d",&n);
        int ans = 0;
        for (int i = 1;i <= n;i ++){
            for (int j = 0;j < 3;j ++)
                scanf("%d",&a[i][j]);
            chos[i] = max_element(a[i],a[i] + 3) - a[i];
            cnt[chos[i]] ++;
            ans += a[i][chos[i]];
        }
        for (int c = 0;c < 3;c ++){
            if (cnt[c] > (n >> 1)){
                priority_queue<int,vector<int>,greater<int> > pq;
                for (int i = 1;i <= n;i ++)
                    if (chos[i] == c)
                        pq.push(a[i][chos[i]] - mid(a[i][0],a[i][1],a[i][2]));
                while (cnt[c] > (n >> 1)){
                    int x = pq.top();
                    pq.pop();
                    ans -= x;
                    cnt[c] --;
                }
                break;
            }
        }
        printf("%d\n",ans);
        memset(cnt,0,sizeof(cnt));
    }
    return 0;
}