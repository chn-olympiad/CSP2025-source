#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans=0,a[10005],aaaa[10005];
priority_queue<pair<int,pair<int,pair<int,int> > > >q,qq;
int find(int x) {
    if (x==a[x]) return x;
    return x=find(a[x]);
}
void f() {
    while (!q.empty()) {
        int a1=q.top().second.first,a2=q.top().second.second.first;
        if (q.top().second.second.second!=0) {
            int o=q.top().second.second.second;
            while (!q.empty()) {
                int za=q.top().first,zb=q.top().second.first,zc=q.top().second.second.first;
                if (q.top().second.second.second==o) qq.push({za+aaaa[o],{zb,{zc,0}}});
                else qq.push(q.top());
                q.pop();
            }
            while (!qq.empty()) {
                q.push(qq.top());
                qq.pop();
            }
            ans+=aaaa[o];
        }
        int a3=q.top().first;
        q.pop();
        if (find(a1)==find(a2)) continue;
        a[find(a2)]=find(a1);
        ans-=a3;
        bool azsx=0;
        for (int i=2;i<=n;i++)
            if (find(i)!=find(i-1)) {
                azsx=1;
                break;
            }
        if (azsx==0) break;
    }
}
int main () {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) a[i]=i;
    for (int i=1;i<=m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        q.push({-c,{a,{b,0}}});
        q.push({-c,{b,{a,0}}});
    }
    for (int i=1;i<=k;i++) {
        int b[1005];
        cin >> aaaa[i];
        for (int j=1;j<=n;j++) {
            cin >> b[j];
            for (int l=1;l<j;l++)
                q.push({-(aaaa[i]+b[l]+b[j]),{j,{l,i}}}),q.push({-(aaaa[i]+b[l]+b[j]),{l,{j,i}}});
        }
    }
    f();
    cout << ans;
    return 0;
}

