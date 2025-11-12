#include <bits/stdc++.h>

using namespace std;
struct AA{
    long long u,v,w,bi;
};
long long n,m,k;
AA e[5101005];
long long b[15];
long long h[500105];
long long ygg[15];
//long long bian[500005];
long long tot = 1;
long long ans = 0x3f3f3f3f3f3f3f3f,sum;
long long fa(long long o){
    if(h[o] == o) return o;
    else return h[o] = fa(h[o]);
}
bool cmp(AA x,AA y){
    return x.w < y.w;
}
void dfs(long long o,long long pp){
    if(sum == k){
            tot = 0;
        for(long long i = 1;i <= n+k+1;i++) h[i] = i;
        for(long long i = 1;i < n+pp;i++){
            while(fa(e[tot].u) == fa(e[tot].v) or !ygg[e[tot].bi]){
                tot++;
                if(tot > m+n*k) break;
            //    cout << e[tot].u << ' ' << e[tot].v << ' ' << e[tot].bi << ':' << endl;
            }
//            bian[i] = tot;
            h[fa(e[tot].u)] = fa(e[tot].v);
            o += e[tot].w;
           // cout << endl;
          //  cout << e[tot].u << ' ' << e[tot].v << ' ' << tot << endl;
        }
        //cout <<endl;
        //cout <<o << endl;
        //cout <<endl;
        ans = min(ans,o);
        return;
    }else{
        //cout << sum;
        sum++;
        dfs(o,pp);
        ygg[sum] = 1;
       // cout << sum << b[sum];
        dfs(o+b[sum],pp+1);
        ygg[sum] = 0;
        sum--;
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n>> m >> k;
    //cout << n;
    for(long long i = 1;i <= m;i++){
        long long x,y,yy;
        cin >> x >> y >> yy;
        e[i].u = x;
        e[i].v = y;
        e[i].w = yy;
        e[i].bi = 0;
    }

    for(long long i = 0;i <k;i++){
        int x,y;
        cin >> b[i+1];
        for(long long j = 1;j <= n;j++){
            cin >> x;
            e[m+i*n+j].u = j;
            e[m+i*n+j].v = n+i+1;
            e[m+i*n+j].w = x;
            e[m+i*n+j].bi = i+1;
        }
    }
    ygg[0] = 1;
    sort(e+1,e+1+m+n*k,cmp);
    dfs(0,0);
    cout <<ans;
    return 0;
}
