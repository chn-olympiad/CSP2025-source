#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
struct node{
    int v[4],cho;
    int down;
};
node a[100005];
int cnt1=0,cnt2=0,cnt3=0;
int ans = 0,mxn;
int d;
bool cmp(node x, node y){
    return x.down<y.down;
}
void solve(){
    ans=cnt1=cnt2=cnt3=0;
    for(int i = 1; i <= n; i++){
        int mx=max(max(a[i].v[1],a[i].v[2]),a[i].v[3]);
        if(a[i].v[1]==mx)cnt1++,ans+=a[i].v[1],a[i].cho=1;
        else if(a[i].v[2]==mx)cnt2++,ans+=a[i].v[2],a[i].cho=2;
        else cnt3++,ans+=a[i].v[3],a[i].cho=3;
    }
    if(cnt1>n/2){
        mxn=1;
        d=cnt1-n/2;
    }else if(cnt2>n/2){
        mxn=2;
        d=cnt2-n/2;
    }else if(cnt3>n/2){
        mxn=3;
        d=cnt3-n/2;
    }else{
        cout << ans << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(a[i].cho==mxn){
            int mxx = -1;
            for(int j = 1; j <= 3; j++)if(j!=mxn)mxx=max(mxx,a[i].v[j]);
            a[i].down=a[i].v[mxn]-mxx;
        }else{
            a[i].down=1e9;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1; i <= d; i++)ans-=a[i].down;
        cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i].v[1]>>a[i].v[2]>>a[i].v[3];
            solve();
    }
    return 0;
}//100pts