#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+100,MAXM=1e6+100;
int n,m,k;
int fa[MAXN];
int Find(int x) {
    return (fa[x]==x ? x : fa[x]=Find(fa[x]));
}
struct dd {
    int u,v;
    long long w;
}a[MAXM];
bool cmp(dd x, dd y) {
    return x.w<y.w;
}
vector<dd > p,q;
long long c[20],val[20][MAXN];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
    for (int i=1;i<=n; i++) {
        fa[i]=i;
    }
	for (int i=1,u,v,w; i<=m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i=0; i<k; i++) {
        cin >> c[i];
        for (int j=1; j<=n; j++) {
            cin >> val[i][j];
        }
	}
	sort(a+1,a+m+1,cmp);
	long long min1=0;
	int cnt=0;
	for(int i=1; i<=m && cnt<n-1; i++) {
        int x=Find(a[i].u),y=Find(a[i].v);
        if (x!=y) {
            cnt++;
            p.push_back(a[i]);
            fa[x]=y;
            min1+=a[i].w;
        }
	}
	for (int i=1; i<(1<<k); i++) {
	    long long ans=0;
	    int len=n;
        for (int o=0; o<k; o++) {
            if ((i>>o)&1) {
                ans+=c[o];
                len++;
            }
        }
        for (int j=1; j<=n+k; j++) {
            fa[j]=j;
        }
        q=p;
        for (int j=1; j<=n; j++) {
            int minn=1e9,min2;
            for (int o=0; o<k; o++) {
                if ((i>>o)&1) {
                    if (val[o][j]<minn) {
                        minn=val[o][j];
                        min2=o;
                    }
                }
            }
            q.push_back({j,min2+n+1,minn});
        }
        sort(q.begin(),q.end(),cmp);
        cnt=0;
        for (int i=0; i<q.size() && cnt<len-1; i++) {
            int x=Find(q[i].u),y=Find(q[i].v);
            if (x!=y) {
                //cout << q[i].u << " " << q[i].v << " " << q[i].w << "\n";
                fa[x]=y;
                ans+=q[i].w;
                cnt++;
            }
        }
        min1=min(min1,ans);
	}
	cout << min1;
	return 0;
}
