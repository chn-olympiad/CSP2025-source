#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

struct road{
    long long from, to, val;
};

bool cmp(road A,road B){
    return A.val < B.val;
}

vector <road> E, newE;

long long c[15], a[15][10005];

long long fa[10015];

long long findfa(long long pos){
    return fa[pos]==0?pos:fa[pos]=findfa(fa[pos]);
}

long long kruscal(long long need){
    //cout << "In kruscal:\n";
    long long ans = 0, cnt = 0;
    sort(E.begin(),E.end(),cmp);
    memset(fa,0,sizeof(fa));
    for(auto e:E){
        if(findfa(e.from)!=findfa(e.to)){
            ans += e.val;
            fa[findfa(e.from)]  = findfa(e.to);
            cnt++;
            newE.push_back(e);
            //cout << e.from << " " << e.to << " " << e.val << "\n";
        }
        if(cnt==need-1){
            break;
        }
    }
    E.clear();
    for(auto e:newE){
        E.push_back(e);
    }
    newE.clear();
    return ans;
}

long long ans;

long long cnt[10015];

void dfs(long long pos,long long cost,long long nowans,long long need){
    //cout << pos << " " << cost << " " << nowans << endl;
    if(pos == k+1){
        ans = min(ans,nowans+cost);
        //cout << nowans << "\n";
        //cout << "return" << "\n";
        return ;
    }
    dfs(pos+1,cost,nowans,need);
    vector <road> oldE;
    cost += c[pos];
    for(auto e:E){
        oldE.push_back(e);
    }
    for(long long j = 1;j <= n;j++){
        E.push_back({pos+n,j,a[pos][j]});
    }
    dfs(pos+1,cost,kruscal(need+1),need+1);
    E.clear();
    for(auto e:oldE){
        E.push_back(e);
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(long long i = 1;i <= m;i++){
        long long u, v, w;
        cin >> u >> v >> w;
        E.push_back({u,v,w});
    }
    for(long long i = 1;i <= k;i++){
        cin >> c[i];
        for(long long j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    ans = kruscal(n);
    dfs(1,0,ans,n);
    cout << ans;
    return 0;
}