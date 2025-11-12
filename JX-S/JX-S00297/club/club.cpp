#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(r);i>=(l);--i)
#define pr pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define bg(x) (x).begin()
#define ed(x) (x).end()
#define sz(x) (int)(x).size()

#define N 202511
#define int long long

int n,c[3],a[N][3],p[N];

inline int get(int i){
    return max({
        (pr){a[i][0],0},
        (pr){a[i][1],1},
        (pr){a[i][2],2}
    }).se;
}

inline void sol(){
    cin>>n;

    c[0]=c[1]=c[2]=0;

    int ans=0;

    rep(i,1,n){
        cin>>a[i][0]>>a[i][1]>>a[i][2];

        int j=get(i);
        ans+=a[i][j];
        c[j]++;
    }

    int cc=max({c[0],c[1],c[2]}),lim=n/2;

    if(cc<=lim){
        cout<<ans<<'\n';
        return;
    }

    int id=-1;

    rep(i,0,2){
        if(c[i]==cc){
            id=i;
            break;
        }
    }

    int re=c[id]-lim;

    rep(i,1,n){
        p[i]=i;
        swap(a[i][0],a[i][id]);
    }

    sort(p+1,p+1+n,[](int x,int y){
        return -a[x][0]+max(a[x][1],a[x][2])>-a[y][0]+max(a[y][1],a[y][2]);
    });

    rep(i,1,n){
        int x=p[i];

        if(get(x)==0){
            ans-=a[x][0];
            ans+=max(a[x][1],a[x][2]);
            re--;
        }

        if(!re){
            break;
        }
    }

    cout<<ans<<'\n';
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        sol();
    }

    /*
    g++ club.cpp -o club -O2 -std=c++14 -Wall -Wextra -Wshadow
    */

    return 0;
}