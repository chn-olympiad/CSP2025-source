#include<bits/stdc++.h>
#define ep emplace
#define eb emplace_back
#define fr(i,l,r) for(int i(l),_##i(r);i<=_##i;i++)
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
template<class T>inline T rd(T&x){
    bool f=1;T a=0;char c=getchar_unlocked();
    for(;c<'0'||c>'9';c=getchar_unlocked())f&=c!='-';
    for(;c>='0'&&c<='9';c=getchar_unlocked())a=c-'0'+a*10;
    return x=f?a:-a;
}template<class T,class...U>inline void rd(T&x,U&...y){rd(x),rd(y...);}
using namespace std;using ll=long long;using ull=unsigned long long;
const int N=1e5+3;
int T,n,a[N][3],b[N],c[3],t[N],ans;

void solve(){
    fr(i,1,rd(n))fr(j,0,2)rd(a[i][j]);
    ans=c[0]=c[1]=c[2]=0;
    fr(i,1,n){
        b[i]=0,c[0]++,ans+=a[i][0];
        if(a[i][1]>a[i][b[i]])ans+=a[i][1]-a[i][b[i]],c[b[i]]--,c[1]++,b[i]=1;
        if(a[i][2]>a[i][b[i]])ans+=a[i][2]-a[i][b[i]],c[b[i]]--,c[2]++,b[i]=2;
    }int id=-1;
    fr(i,0,2)if(c[i]>n/2)id=i;
    if(id==-1)return void(cout<<ans<<'\n');
    *t=0;
    fr(i,1,n)if(b[i]==id){
        t[++*t]=1e9;
        fr(j,0,2)if(j^id)t[*t]=min(t[*t],a[i][id]-a[i][j]);
    }sort(t+1,t+*t+1);
    fr(i,1,c[id]-n/2)ans-=t[i];
    cout<<ans<<'\n';
}

int main(){
    file(club);
    for(rd(T);T--;)solve();
    return 0;
}