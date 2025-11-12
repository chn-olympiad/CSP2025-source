#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
using namespace std;
const int Siz=1<<18;char buf[Siz],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,Siz,stdin),p1==p2)?EOF:*p1++
int read(){
    int a=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') a=a*10+ch-'0',ch=getchar();
    return a;
}
const int N=1e5+10;
int n,a[N][3],b[N][3],cnt[3],ans,d[N];
int solve(){
    n=read();cnt[0]=cnt[1]=cnt[2]=ans=0;for(int i=1,mx;i<=n;i++){
        a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
        mx=max({a[i][0],a[i][1],a[i][2]});ans+=mx;
        mx==a[i][0]?b[++cnt[0]][0]=i:mx==a[i][1]?b[++cnt[1]][1]=i:b[++cnt[2]][2]=i;
    }if(max({cnt[0],cnt[1],cnt[2]})<=n/2) return ans;
    int k=0;while(cnt[k]<=n/2) k++;
    for(int i=1,j;i<=cnt[k];i++) j=b[i][k],d[i]=min(a[j][k]-a[j][(k+1)%3],a[j][k]-a[j][(k+2)%3]);
    sort(d+1,d+cnt[k]+1);for(int i=1;i<=cnt[k]-(n/2);i++) ans-=d[i];
    return ans;

}
signed main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int T=read();while(T--) printf("%lld\n",solve());return 0;
}