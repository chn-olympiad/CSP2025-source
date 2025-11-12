#include<bits/stdc++.h>
#define EQ ==
using namespace std;
const int N=100100;
int n,a[N][3],cnt[3],ans=0;
struct hhh{
    int mx,sc,cha,bh[2];
} b[N];
inline bool cmp(const hhh& x,const hhh& y){
    return x.cha>y.cha;
}
inline void solve(){
    memset(b,0,sizeof(b));
    cin>>n;cnt[0]=cnt[1]=cnt[2]=ans=0;
    set<int> num[3];
    for(int t=1;t<=n;t++){
        for(int i=0;i<=2;i++){
            cin>>a[t][i];
            if(a[t][i]>b[t].mx){
                b[t].sc=b[t].mx;b[t].mx=a[t][i];
                b[t].bh[1]=b[t].bh[0];b[t].bh[0]=i;
            }
            else if(a[t][i]>b[t].sc){
                b[t].sc=a[t][i];
                b[t].bh[1]=i;
            }
        }
        b[t].cha=b[t].mx-b[t].sc;
    }
    sort(b+1,b+n+1,cmp);
    for(int t=1;t<=n;t++){
        if(cnt[b[t].bh[0]] EQ n/2){
            ans+=b[t].sc;cnt[b[t].bh[1]]++;
        }
        else{
            ans+=b[t].mx;cnt[b[t].bh[0]]++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cout.tie(0)->ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}