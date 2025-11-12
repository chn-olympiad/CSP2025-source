#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+5,M = 1e6+5,K = 12;
int n,m,k;
struct aa{
    int u,v,w;
}e[M],e2[N<<1],e3[N<<1],e4[N<<1];
int cnt,ans;
int f[N<<1];
int find(int x){
    if(f[x] == x){
        return x;
    }
    return f[x] = find(f[x]);
}
aa num[K][N];
bool cmp(aa x,aa y){
    return x.w < y.w;
}
int c[K];
queue<int>q;
vector<pair<int,int> >vec[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
    sort(e+1,e+1+m,cmp);
    for(int i = 1;i <= m;i++){
        int u = find(e[i].u),v = find(e[i].v),w = e[i].w;
        if(u != v){
            f[v] = u;
            ans += w;
            cnt++;
            e2[cnt] = e4[cnt] = e[i];
        }
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            cin >> num[i][j].w;
            num[i][j].u = i+n,num[i][j].v = j;
        }
        sort(num[i]+1,num[i]+1+n,cmp);
    }
    for(int i = 0;i < (1<<k);i++){
        int an = 0,ccnt = cnt;
        for(int j = 1;j <= n+k;j++){
            f[j] = j;
        }
        for(int j = 0;j < k;j++){
            if((i>>j)&1){
                an += c[j+1];
                for(int x = 1;x <= cnt;x++){
                    e3[x] = e2[x];
                }
                int n1 = 1,n2 = 1;
                int ct = 0;
                while(n1 <= cnt || n2 <= n){
                    if(n2 > n || (n1 <= cnt && e3[n1].w <= num[j+1][n2].w)){
                        e2[++ct] = e3[n1];
                        n1++;
                    }
                    else{
                        e2[++ct] = num[j+1][n2];
                        n2++;
                    }
                }
                cnt = ct;
                //for(int x = 1;x <= n;x++){
                //    e2[++cnt] = num[j+1][x];
                //}
            }
        }
        //sort(e2+1,e2+1+cnt,cmp);
        for(int j = 1;j <= cnt;j++){
            int u = find(e2[j].u),v = find(e2[j].v),w = e2[j].w;
            if(u != v){
                f[v] = u;
                an += w;
            }
        }
        cnt = n-1;
        for(int j = 1;j < n;j++){
            e2[j] = e4[j];
        }
        ans = min(ans,an);
    }
    cout << ans;
}
