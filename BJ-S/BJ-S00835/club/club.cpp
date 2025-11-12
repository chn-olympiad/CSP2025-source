#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=1;i<=(n);++i)
#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define reb(i,n) for(int i=0;i<(n);++i)
using namespace std;
const int N=1e5+7;
double Time(){
    return 1.*clock()/CLOCKS_PER_SEC;
}
int a[N][3],n;
priority_queue<int,vector<int>,greater<int> >q;
int to[N],cnt[3];
int solve(){
    int ans=0;
    cin>>n;
    rep(i,n){
        reb(j,3)
        cin>>a[i][j];
        to[i]=0;
        reb(j,3)if(a[i][j]>a[i][to[i]])to[i]=j;
        cnt[to[i]]++;ans+=a[i][to[i]];
    }
    int sp=-1;
    reb(j,3)if(cnt[j]>(n/2))sp=j;
    if(sp==-1){
        reb(i,3)cnt[i]=0;
        while(q.size())q.pop();
        cout<<ans<<"\n";
        return 0;
    }
    rep(i,n)if(to[i]==sp){
        int mxx=0;
        reb(j,3)if(a[i][j]>=mxx&&j!=to[i])mxx=a[i][j];
        q.push(a[i][sp]-mxx);
    }
    while(cnt[sp]>(n/2)){
        --cnt[sp];ans-=q.top();q.pop();
    }
    reb(i,3)cnt[i]=0;
    while(q.size())q.pop();
    cout<<ans<<"\n";
    return 0;
}
main(){
    FILE("club");
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    // cout<<Time()<<'\n';
    return 0;
}