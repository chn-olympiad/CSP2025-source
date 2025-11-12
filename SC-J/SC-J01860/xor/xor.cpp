#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int N=1e5+5,logN=20;
using namespace std;

int f[N][logN],k,n;

int get1(int x){
    int num=1,now=2;
    while(x){
        if(x&1) num*=now;
        now*=now;
        x>>=1;
    }
    return num;
}

int get2(int x,int len){
    int num=0;
    for(int u=20;u>=0;u--){
        if(len&(1<<u)){
            num^=f[x][u],x+=get1(u);
        }
    }
    return num;
}

struct edge{
    int l,r;
};
vector<edge> a;

bool cmp(edge x,edge y){
    if(x.r==y.r){
        return x.l>y.l;
    }
    else{
        return x.r<y.r;
    }
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> f[i][0];
    //cout << n << " " << k << endl;
    rep(u,1,logN)
        rep(i,1,n){
            if(i+get1(u)-1>n) continue;
            f[i][u]=f[i][u-1]^f[i+get1(u-1)][u-1];
        }

    rep(len,1,n)
        rep(i,1,n-len+1){
            if(get2(i,len)==k) a.push_back({i,i+len-1});
        }
    sort(a.begin(),a.end(),cmp);
    /*for(edge x:a){
        cout << x.l << " " << x.r << endl;
    }*/
    int now=0,ans=0;
    for(edge x:a){
        if(now<x.l) ans++,now=x.r;
    }
    //cout << a.size() << " ";
    cout << ans;
}
