#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);(i)<=(r);++(i))
#define rep1(i,l,r) for(int i=(l);(i)<(r);++(i))
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define il inline
#define cst const
#define csti const int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
//#define int long long
//#define LLL

#ifdef LLL
csti inf=0x3f3f3f3f3f3f3f3fll;
#else
csti inf=0x3f3f3f3f;
#endif // LLL

csti N=1e6+7,mod=1;

int n,m,a[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int cnt=n*m;
    rep(i,1,cnt){
        cin>>a[i];
    }int me=a[1];
    sort(a+1,a+cnt+1,greater<int>());
    int x=1,y=1,now=1;
    while(me!=a[now]){
        if(y&1)x++;
        else x--;
        now++;
        if(x>n)++y,x=n;
        else if(x<1)++y,x=1;
        //cout<<me<<' '<<now<<'\n';
    }cout<<y<<' '<<x;
    return 0;
}
