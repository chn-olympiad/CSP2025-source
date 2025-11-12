#include<bits/stdc++.h>
#define N 100010
#define INF 1e9
using namespace std;
int t, n;
int ans=0, vis[N], b[N];
int f[510][510][510];
struct member{
    int id;
    int s1, s2, s3;
    bool operator < (const member &u) const{
        return u.s2-u.s1 > s2-s1;
    }
}a[N];
priority_queue<member> q1;
inline int read(){
    char ch=getchar(); int x=0, f=1;
    while(!isdigit(ch)) {f=(ch=='-')?-1:1; ch=getchar();}
    while(isdigit(ch)) {x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
bool cmp1(member x, member y){
    if(x.s1==y.s1) return x.s2>y.s2;
    return x.s1>y.s1;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    t=read();
    while(t--){
        n=read();
        ans = 0;
        for(int i=1; i<=n; i++){
            a[i].s1=read(), a[i].s2=read(), a[i].s3=read();
            a[i].id = i;
        }
        if(n<=450){
            for(int i=1; i<=n; i++)
                for(int j=0; j<=n/2; j++)
                    for(int k=0; k<=n/2; k++)
                        f[i][j][k] = 0;
            for(int i=1; i<=n; i++){
                for(int j=0; j<=min(i, n/2); j++){
                    for(int k=0; k<=min(i-1-j, n/2); k++){
                        if((i-1)-j-k > n/2) continue;
                        if(j+1<=n/2) f[i][j+1][k] = max(f[i][j+1][k], f[i-1][j][k]+a[i].s1);
                        if(k+1<=n/2) f[i][j][k+1] = max(f[i][j][k+1], f[i-1][j][k]+a[i].s2);
                        if(i-j-k<=n/2) f[i][j][k] = max(f[i][j][k], f[i-1][j][k]+a[i].s3);
                        ans = max(max(ans, f[i][j+1][k]), max(f[i][j][k+1], f[i][j][k]));
                    }
                }
            }
            printf("%d\n", ans);
            continue;
        }
        memset(vis, 0, sizeof(vis));
        while(!q1.empty()) q1.pop();
        sort(a+1, a+n+1, cmp1);
        for(int i=1; i<=n/2; i++){
            q1.push(a[i]);
            vis[a[i].id] = 1;
        }
        for(int i=n/2+1; i<=n; i++){
            member u = q1.top();
            if(a[i].s2-a[i].s1 < u.s2-u.s1){
                q1.pop();
                q1.push(a[i]); vis[a[i].id] = 1;
                vis[u.id] = 2;
            }
            else vis[a[i].id] = 2;
        }
        for(int i=1; i<=n; i++){
            if(vis[a[i].id]==1){
                ans += a[i].s1;
                b[i] = a[i].s3-a[i].s1;
            }
            if(vis[a[i].id]==2){
                ans += a[i].s2;
                b[i] = a[i].s3-a[i].s2;
            }
        }
        sort(b+1, b+n+1);
        for(int i=n; i>=n/2+1; i--){
            if(b[i]<=0) break;
            ans+=b[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
