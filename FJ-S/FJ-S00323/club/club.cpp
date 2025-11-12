#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

const int N = 1e5+5,inf=1e9;
int n,a[N][5],d[N],cnt[5],id;
ll ans=0;priority_queue<int>pq;

void solve(){
    n=read();cnt[1]=cnt[2]=cnt[3]=ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)a[i][j]=read();
    for(int i=1;i<=n;i++){d[i]=1;
        if(a[i][d[i]]<a[i][2])d[i]=2;
        if(a[i][d[i]]<a[i][3])d[i]=3;
        cnt[d[i]]++;ans+=a[i][d[i]];
    }id=0;for(int i=1;i<=3;i++)if(cnt[i]>n/2)id=i;
    if(id==0)return printf("%lld\n",ans),void();
    while(pq.size())pq.pop();
    for(int i=1;i<=n;i++)if(d[i]==id){int mx=-inf;
        for(int j=1;j<=3;j++)if(j!=id&&(a[i][j]-a[i][id])>mx)mx=(a[i][j]-a[i][id]);
        pq.emplace(mx);
    }
    while(pq.size()&&cnt[id]>n/2){
        cnt[id]--;ans+=pq.top();pq.pop();
    }printf("%lld\n",ans);
}

int main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int T=read();while(T--)solve();
    return 0;
}