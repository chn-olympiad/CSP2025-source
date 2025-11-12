#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
using namespace std;

const int N=1e5+10;
int T,n,ans;
pair<int,int>a[N][3],c[3];
vector<int>v[3];

void solve(){
    scanf("%d",&n);
    for(int i=0;i<3;i++)c[i]={0,i},v[i].clear();
    ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)scanf("%d",&a[i][j].fi),a[i][j].se=j;
        sort(a[i],a[i]+3);
        ans+=a[i][2].fi;
        v[a[i][2].se].push_back(a[i][2].fi-a[i][1].fi);
        c[a[i][2].se].fi++;
    }
    sort(c,c+3);
    if(c[2].fi>n/2){
        sort(v[c[2].se].begin(),v[c[2].se].end());
        for(int i=0;i<c[2].fi-n/2;i++)ans-=v[c[2].se][i];
    }
    printf("%d\n",ans);
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}