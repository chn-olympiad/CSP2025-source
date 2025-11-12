#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define forto(i,a,b) for(int i(a),_##i(b);i<=_##i;i++)
#define forbk(i,a,b) for(int i(a),_##i(b);i>=_##i;i--)
#define forv(i,a) for(int i(0),_##i(a);i<_##i;i++)
#define il inline
#define mkp make_pair
#define eb emplace_back
using namespace std;
il int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N=100005;
int n,a[N][3],cnt[3],c[N];
il void work(){
    n=read();
    cnt[0]=cnt[1]=cnt[2]=0;
    ll ans=0;
    forto(i,1,n){
        int mx=0;
        forv(j,3)a[i][j]=read(),mx=max(mx,a[i][j]);
        ans+=mx;
        forv(j,3)if(a[i][j]==mx){c[i]=j,cnt[j]++;break;}
    }
    int ex=-1;
    forv(j,3)if(cnt[j]>n/2)ex=j;
    if(ex!=-1){
        vector<int>v;
        forto(i,1,n)if(c[i]==ex){
            int t=0x3f3f3f3f;
            forv(j,3)if(j!=ex)t=min(t,a[i][ex]-a[i][j]);
            v.eb(t);
        }
        sort(v.begin(),v.end());
        forv(i,cnt[ex]-n/2)ans-=v[i];        
    }
    printf("%lld\n",ans);
}

signed main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    int t=read();
    while(t--)work();
    return 0;
}