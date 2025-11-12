#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,V=10001,mod=998244353;
template<class T>
void add(T& x,const T& y){
    x=(x+y>=mod?x+y-mod:x+y);
}
struct poly{
    int f[N<<1];
    void update(int x){
        ll cur=0;
        for(int i=V-x+1;i<=V;i++)
            cur+=f[i];
        for(int i=V-x;i>=0;i--)
            add(f[i+x],f[i]);
        f[V]=(f[V]+cur)%mod;
    }
    int operator [](int x){
        return f[x];
    }
}F;
int cnt[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    F.f[0]=1;
    int m=5000;
    ll res=0;
    for(int i=1;i<m;i++){
        while(cnt[i]){
            F.update(i);
            --cnt[i];
        }
        res+=F[i*2+1]+F[i*2+2];
    }
    while(cnt[m]){
        F.update(m);
        --cnt[m];
    }
    res+=F[V];
    cout<<res%mod;
}