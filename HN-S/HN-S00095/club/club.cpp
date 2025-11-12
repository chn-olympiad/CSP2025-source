#include<bits/stdc++.h>
#define int long long
using namespace std;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin)),p1==p2?EOF:*p1++)
char buf[1<<23],*p1=buf,*p2=buf;
int read(){char c=getchar();int p=0,flg=1;while(c<'0'||c>'9'){if(c=='-') flg=-1;c=getchar();}while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}return p*flg;}
int T,n,b[100010],cnt[3];array<int,3>a[100010];
void solve(){
    n=read();for(int i=1;i<=n;i++) for(int j:{0,1,2}) a[i][j]=read();
    for(int i:{0,1,2}) cnt[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i][0]>=max(a[i][1],a[i][2])) cnt[b[i]=0]++;
        else if(a[i][1]>=max(a[i][0],a[i][2])) cnt[b[i]=1]++;
        else cnt[b[i]=2]++;
        ans+=a[i][b[i]];
    }
    if(max({cnt[0],cnt[1],cnt[2]})<=n/2){cout<<ans<<'\n';return ;}
    int id=(cnt[0]>n/2?0:cnt[1]>n/2?1:2);
    vector<int>V;
    for(int i=1;i<=n;i++) if(b[i]==id){
        int mx=-1e18;
        for(int j:{0,1,2}) if(j^id) mx=max(mx,a[i][j]-a[i][id]);
        V.push_back(mx);
    }
    sort(V.begin(),V.end(),greater<>());
    for(int i=0;i<cnt[id]-n/2;i++) ans+=V[i];
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    T=read();while(T--) solve();
    return 0;
}