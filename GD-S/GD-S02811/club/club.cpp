#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,r,l) for(int i=(r);i>=(l);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define ll long long
#define ull unsigned long long
#define it128 __int128
#define vi vector<int>
#define pi pair<int,int>
#define fi first
#define se second
#define vp vector<pi>
#define pl pair<ll,ll>
#define Size(x) ((int)x.size())
const int N=1e5+5;
int n,a[N][3],d[N],c[3];
int v[N],tot;
void Main() {
    cin>>n;
    ll ans=0;
    c[0]=c[1]=c[2]=0;
    fo(i,1,n) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        int Max=max(a[i][0],max(a[i][1],a[i][2]));
        if(a[i][0]==Max) d[i]=0,c[0]++;
        else if(a[i][1]==Max) d[i]=1,c[1]++;
        else d[i]=2,c[2]++;
        ans+=Max;
    }
    int T=-1;
    if(c[0]>n/2) T=0; 
    else if(c[1]>n/2) T=1;
    else if(c[2]>n/2) T=2;
    if(T!=-1) {
        tot=0;
        fo(i,1,n) if(d[i]==T) {
            int Max=-2e9;
            fo(j,0,2) if(j!=T) Max=max(Max,a[i][j]-a[i][T]);
            v[++tot]=Max;
        }
        sort(v+1,v+1+tot,greater<>());
        int to=c[T]-n/2;
        fo(i,1,to) ans+=v[i];
    }
    cout<<ans<<'\n';
}
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int Test=1;
    cin>>Test;
    while(Test--) {
        Main();
    }
}