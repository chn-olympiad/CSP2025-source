// GZ-S00003 丁思源   贵阳市华师一学校

#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define ll int

#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define vi vector<ll>
#define pb push_back
#define SZ(x)  ((int)x.size())
#define BG(x) (x.begin())
#define ED(x) (x.end())
#define pii pair<ll,ll>
#define x first
#define y seconde
#define mkp make_pair
#define gmin(x,y) (x=min(x,y))
#define gmax(x,y) (x=max(x,y))
#define MD(x) ((x)%=mod)
#define ppct __builtin_popcountll

 
namespace Mine {
    #define gc getchar
    ll read() {
        ll x=0,t=1;
        char ch=gc();
        while(ch<'0' || ch>'9') t=(ch=='-'?-1:t),ch=gc();
        while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=gc();
        return t*x;
    }
    #undef gc
    const int N=1e5+100;
    ll a[N][3],pos[N],cnt[10];
    ll n;
    void main() {
        memset(cnt,0,sizeof cnt);
        n=read();
        // cout<<n<<" "<<endl;
        ll lim=n/2;
        ll ans=0;
        For(i,1,n) {
            For(j,0,2) a[i][j]=read();
            For(j,0,2) if(a[i][j]>=a[i][pos[i]]) pos[i]=j;
            cnt[pos[i]]++;
            ans+=a[i][pos[i]];
        }
        ll m=-1,mx=0;
        For(j,0,2) if(cnt[j]>lim) m=j,mx=cnt[j];
        if(m==-1) {
            cout<<ans<<"\n";
            return ;
        }
        // puts("QAQ");
        priority_queue<ll> q;
        For(i,1,n) {
            if(pos[i]==m) {
                ll tmp=-1e18;
                For(j,0,2) if(j!=m) gmax(tmp,a[i][j]-a[i][m]);
                q.push(tmp);
            }
        }
        while(mx>lim) {
            ans+=q.top();
            q.pop();
            mx--;
        }
        cout<<ans<<"\n";
        return ; 
    }
}

signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll _=Mine::read();
    while(_--) Mine::main();

    return 0;
}