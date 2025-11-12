#include<bits/stdc++.h>
using namespace std;
#define LOCAL
#define ll long long
const int N = 5000004;
void read(ll &x){
    char c = getchar_unlocked();
    bool f = 0;
    x = 0;
    while(c<'0'||c>'9'){
        if(c=='-')f = -f;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x = x*10+(c-'0');
        c=getchar_unlocked();
    }
    if(f)x = -x;
}
struct S{
    ll u,v,w;
    bool operator< (S &s)const{
        return w<s.w;
    }
}L[N];
int f[N+5];
#define find fghjkl
#define merge ertyui
ll find(ll x){
    if(f[x] == x)return x;
    return find(f[x]);
}
bool merge(ll x,ll y){
    x = find(x);y = find(y);
    if(x != y){
        f[x] = y;
        return true;
    }return false;
}
vector<pair<int,int> >G[N];
int main(){
    #ifdef LOCAL
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif // LOCAL
    ll n,m,k;read(n);read(m);read(k);
    for(int i=1;i<=n+k+10;i++)f[i] = i;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        read(u);
        read(v);
        read(w);
        L[i] = {u,v,w};
    }
    if(k == 0){
        sort(L+1,L+1+m);
        ll ans = 0;
        //MST
        vector<S>li;
        for(int i=1;i<=m;i++){
            if(merge(L[i].u,L[i].v)){
                ans += L[i].w;
            }
        }
        cout<<ans<<endl;
        return 0;
    }else{
        int tot=0;
        for(int i=1;i<=k;i++){
            ll c;
            read(c);
            ll w;
            for(int j=1;j<=n;j++){
                read(w);
                if(w == 0){
                    merge(j,n+i);
                }else{
                    tot++;
                    L[m+tot] = {n+i,j,w};
                }
            }
        }
        sort(L+1,L+1+m+tot);
        ll ans = 0;
        for(int i=1;i<=m+tot;i++){
            if(merge(L[i].u,L[i].v)){
                ans += L[i].w;
            }
        }
        cout<<ans<<endl;
    }

}
