#include <bits/stdc++.h>
#define lint __int128
#define int long long
#define fi first
#define se second
#define Il inline
#define vec vector
#define pb push_back
#define IT ::iterator
#define p_q priority_queue

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef double db;
const int N=1e5;
const db eps=1e-9;

// bool P1;

int T,n,ans,c[5];
pii b[5];
p_q<int>pq[5];

Il void yuanshenqidong(){
    ans=0,c[1]=c[2]=c[3]=0;
    while(!pq[1].empty()){
        pq[1].pop();
    }
    while(!pq[2].empty()){
        pq[2].pop();
    }
    while(!pq[3].empty()){
        pq[3].pop();
    }
    cin>>n;
    for(int i=1,x,y,z;i<=n;i++){
        cin>>x>>y>>z;b[1]={x,1},b[2]={y,2},b[3]={z,3};
        sort(b+1,b+4,greater<pii>());
        ans+=b[1].fi,c[b[1].se]++,pq[b[1].se].push(b[2].fi-b[1].fi);
    }
    // cout<<"CHECK:"<<ans<<'\n';
    if(c[1]>(n>>1)){
        for(int i=1;i<=c[1]-(n>>1);i++){
            ans+=pq[1].top(),pq[1].pop();
        }
    }else if(c[2]>(n>>1)){
        for(int i=1;i<=c[2]-(n>>1);i++){
            ans+=pq[2].top(),pq[2].pop();
        }
    }else if(c[3]>(n>>1)){
        for(int i=1;i<=c[3]-(n>>1);i++){
            ans+=pq[3].top(),pq[3].pop();
        }
    }
    cout<<ans<<'\n';
    return;
}

// bool P2;

signed main(){
    // system("diff club5.ans club.out -Z");return 0;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<abs((&P1)-(&P2))/1024/1024;return 0;
    cin>>T;
    while(T--){
        yuanshenqidong();
    }
    return 0;
}