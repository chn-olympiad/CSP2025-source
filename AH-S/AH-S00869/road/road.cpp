#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;

struct node{
    int u,v,w;
}e[N],ek[15][2000],e1[N],e2[N];

int n,m,k,c[N],a[15][2000],fa[N],tot;

bool cmp(node n1,node n2){
return n1.w < n2.w;
}

int found(int u){
    if(u == fa[u]) return u;
    else return fa[u] = found(fa[u]);
}

int MST(){
    for(int i = 1;i <= n + k;i ++) fa[i] = i;
    int ans = 0;
    for(int i = 1;i <= m;i ++){
        if(found(e[i].u) != found(e[i].v)){
            ans += e[i].w;
            fa[found(e[i].u)] = found(e[i].v);
        }
    }
    return ans;
}

int MST2(){
    for(int i = 1;i <= n + k;i ++) fa[i] = i;
    int ans = 0;
    for(int i = 1;i <= m;i ++){
        if(found(e2[i].u) != found(e2[i].v)){
            ans += e2[i].w;
            fa[found(e2[i].u)] = found(e2[i].v);
        }
    }
    return ans;
}

void solve1(){
	//cout << 1 << ' ';
    for(int i = 1;i <= k;i ++){
        for(int j = 1;j <= n;j ++){
            e[++m] = {i + n,j,a[i][j]};
        }
    }
    sort(e + 1,e + m + 1,cmp);
    for(int i = 1;i <= n + k;i ++) fa[i] = i;
    int ans = 0;
    for(int i = 1;i <= m;i ++){
        if(found(e[i].u) != found(e[i].v)){
            ans += e[i].w;
            fa[found(e[i].u)] = found(e[i].v);
        }
    }
    cout << ans << '\n';
}

void merges(){
    int cnt = 1;
    for(int i = 0,j = 0;;){
        if(i >= m) e2[cnt] = e1[++j];
        else if(j >= tot) e2[cnt] = e[++i];
        else if(e[i + 1].w < e1[j + 1].w) e2[cnt] = e[++i];
        else e2[cnt] = e1[++j];
        if(cnt == m + tot) break;
        cnt ++;
    }
    m = cnt;
}

void solve2(){
    for(int i = 1;i <= k;i ++){
        for(int j = 1;j <= n;j ++){
            ek[i][j] = {i + n,j,a[i][j]};
        }
        sort(ek[i] + 1,ek[i] + n + 1,cmp);
    }
    if(k == 0){
        cout << MST();return;
    }
    int ans = 1e18;
    for(int s = 0;s <= (1 << k) - 1;s ++){
		//cout << s << ' ';
        int tmp = m,sum = 0;tot = 0;
        for(int i = 0;i < k;i ++){
            if(s & (1 << i)){
				//cout << i + 1 << ' ';
				sum += c[i + 1];
                for(int j = 1;j <= n;j ++){
                    e1[++tot] = ek[i + 1][j];
                }
            }
        }

        sort(e1 + 1,e1 + tot + 1,cmp);
        //for(int i = 1;i <= tot;i ++) cout << e1[i].w << ' ';
        //cout << '\n';
        merges();
        //for(int i = 1;i <= m;i ++) cout << e2[i].u << ' ' << e2[i].v << ' ' << e2[i].w << '\n';
        ans = min(ans,MST2() + sum);
        m = tmp;
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i ++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1,e + m + 1,cmp);
    int flag = 1;
    for(int i = 1;i <= k;i ++){
        cin >> c[i];
        if(c[i]) flag = 0;
        int tmp = 0;
        for(int j = 1;j <= n;j ++){
            cin >> a[i][j];
            if(a[i][j] == 0) tmp = 1;
        }
        if(!tmp) flag = 0;
    }
    if(flag) solve1();
    else solve2();


    return 0;
}
