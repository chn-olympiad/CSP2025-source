#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <vector>
#include <queue>
#include <random>
#include <time.h>
#define int long long
// #define ll long long
// #define db double
// #define db long double
// #define i128 __int128
#define pi pair<int,int>
#define fi first
#define se second

using namespace std;

const int N=1e5+10;

int T,n,a[N][4],cnt[4],ans;

inline void sol(){
    memset(cnt,0,sizeof(cnt));
    ans=0;
    cin>>n;
    priority_queue<pi,vector<pi>,greater<pi>> q;
    for(int i(1);i<=n;++i){
        for(int j(1);j<=3;++j){
            cin>>a[i][j];
        }
        int maxn=max(max(a[i][1],a[i][2]),a[i][3]);
        ans+=maxn;
        if(maxn==a[i][1]){
            cnt[1]++;
            q.push(make_pair(maxn-max(a[i][2],a[i][3]),1));
        }
        else if(maxn==a[i][2]){
            cnt[2]++;
            q.push(make_pair(maxn-max(a[i][1],a[i][3]),2));
        }
        else{
            cnt[3]++;
            q.push(make_pair(maxn-max(a[i][1],a[i][2]),3));
        }
    }
    int id=1;
    if(cnt[2]>cnt[id]){
        id=2;
    }
    if(cnt[3]>cnt[id]){
        id=3;
    }
    while(cnt[id]>n/2){
        int x=q.top().fi,y=q.top().se;
        q.pop();
        if(y!=id){
            continue;
        }
        ans-=x;
        cnt[id]--;
    }
    cout<<ans<<'\n';
    return;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    // T=1;
    while(T--){
        sol();
    }
    return 0;
}