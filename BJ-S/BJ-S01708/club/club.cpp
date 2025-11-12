#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
#define int long long
const int N=100005;
int n,a[N][4],cnt[4],ch[N];

void solve(){
    memset(a,0,sizeof a);
    memset(cnt,0,sizeof cnt);
    memset(ch,0,sizeof ch);
    cin>>n;
    _for(i,1,n){
        _for(j,1,3)
            cin>>a[i][j];
    }
    int ans=0;
    _for(i,1,n){
        int maxn=0;
        maxn=max({a[i][1],a[i][2],a[i][3]});
        ans+=maxn;
        if(maxn==a[i][1]){
            cnt[1]++;
            ch[i]=1;
        }else if(maxn==a[i][2]){
            cnt[2]++;
            ch[i]=2;
        }else{
            cnt[3]++;
            ch[i]=3;
        }
    }
    if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
        cout<<ans<<'\n';
        return ;
    }
    vector<int> choice;
    int zu;
    if(cnt[1]>n/2) zu=1;
    else if(cnt[2]>n/2) zu=2;
    else zu=3;
    _for(i,1,n){
        int maxn=0;
        _for(j,1,3) if(j!=zu) maxn=max(maxn,a[i][j]);
        if(ch[i]==zu){
            choice.push_back(-a[i][zu]+maxn);
        }
    }
    sort(choice.begin(),choice.end(),greater<int>());
    int yu=cnt[zu]-n/2;
    assert((int)choice.size()>=yu);
    _for(i,0,yu-1){
        ans+=choice[i];
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
