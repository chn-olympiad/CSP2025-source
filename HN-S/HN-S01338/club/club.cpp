#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int INF=1e18;
int mx[N],cd[N],n,a[N][3],ans;
vector<int> c[3];
bool cmp(int A,int B){
    return cd[A]-mx[A]>cd[B]-mx[B];
}
void solve(){
    
    cin>>n;ans=0;c[0].clear();c[1].clear();c[2].clear();
    for(int i=1;i<=n;++i){
        int id=0;
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        for(int j=0;j<3;++j){
            if(a[i][j]>a[i][id])id=j;
        }
        mx[i]=cd[i]=-INF;
        for(int j=0;j<3;++j){
            if(a[i][j]>mx[i])cd[i]=mx[i],mx[i]=a[i][j];
            else if(a[i][j]>cd[i])cd[i]=a[i][j];
        }
        c[id].push_back(i);
        ans+=mx[i];
    }
    for(int i=0;i<3;++i)if(c[i].size()*2>n){
        sort(c[i].begin(),c[i].end(),cmp);
        int len=c[i].size();
        for(int j=0;j<(len-n/2);++j)ans+=cd[c[i][j]]-mx[c[i][j]];
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
