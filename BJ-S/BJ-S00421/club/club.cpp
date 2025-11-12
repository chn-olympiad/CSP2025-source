#include <bits/stdc++.h>
#define fin(str) freopen(str,"r",stdin)
#define fout(str) freopen(str,"w",stdout)
#define pii pair<int,int>
#define fir first
#define sec second
#define P(x,y) make_pair(x,y)
#define ll long long
using namespace std;
bool BG;

const int maxn=1e5+5;
const int inf=1e9;

int n,a[maxn][4],cnt[4];
vector <int> id[4];
vector <int> d;
int ans;

inline void solve(){
    ans=0;
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<=2;i++) id[i].clear();
    d.clear();

    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);

    for (int i=1;i<=n;i++){
        int p=0;
        for (int j=1;j<=2;j++){
            if (a[i][j]>a[i][p]){
                p=j;
            }
        }
        ans+=a[i][p];
        cnt[p]++;
        id[p].push_back(i);
    }

    int p=0;
    for (int i=1;i<=2;i++) if (cnt[i]>cnt[p]) p=i;

    for (int i=0;i<id[p].size();i++){
        int x=id[p][i];
        int maxval=-inf;
        for (int j=0;j<=2;j++){
            if (j==p) continue;
            maxval=max(maxval,a[x][j]-a[x][p]);
        }
        d.push_back(maxval);
    }

    sort(d.begin(),d.end());

    for (int i=1;i<=max(0,(int)d.size()-n/2);i++){
        int x=(int)d.size()-i;
        ans+=d[x];
    }

    printf("%d\n",ans);
}


int T;

bool ED;
int main(){
    fin("club.in");
    fout("club.out");

    scanf("%d",&T);
    while (T--) solve();

    cerr<<"Memory : "<<1.0*(&ED-&BG)/1048576<<"Mb\n";
    return 0;
}
