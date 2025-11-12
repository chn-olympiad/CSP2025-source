#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define ep emplace
#define pii pair<int,int>
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn][3];
// priority_queue<ll> q[3];
int q[3][maxn],len[3];
void matt(int _cases){
    len[0]=len[1]=len[2]=0;
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        int mx=max(max(a[i][0],a[i][1]),a[i][2]);
        ans+=mx;
        if(a[i][0]==mx) q[0][++len[0]]=(max(a[i][1],a[i][2])-a[i][0]);
        else if(a[i][1]==mx)    q[1][++len[1]]=(max(a[i][0],a[i][2])-a[i][1]);
        else q[2][++len[2]]=(max(a[i][0],a[i][1])-a[i][2]);
    }
    for(int o=0;o<3;o++){
        if(len[o]>n/2){
            sort(q[o]+1,q[o]+len[o]+1);
            for(int i=n/2+1;i<=len[o];i++)  ans+=q[o][i];
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int T;scanf("%d",&T);for(int i=1;i<=T;i++)matt(i);
}