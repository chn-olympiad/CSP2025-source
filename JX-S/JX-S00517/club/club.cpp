//remember:
//freopen!!!
//mod!!!
//time limit and memory limit!!!
//the special numbers!!!

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,ans;
int a[N],b[N],c[N];
int f[2][110][110];
struct node{
    int d,e;
}g[N],h[N];
bool cmp(node x,node y){
    return x.d>y.d;
}
bool cmp2(node x,node y){
    return x.e>y.e;
}
void solve(){
    cin>>n;
    ans=0;
    bool flag1=1,flag2=1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]!=0||c[i]!=0)
            flag1=0;
        if(c[i]!=0)
            flag2=0;
    }
    if(n<=200){
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(n/2,i);j++)
                for(int k=0;k<=min(n/2,i-j);k++){
                    f[1][j][k]=0;
                    if(j>=1)
                        f[1][j][k]=f[0][j-1][k]+a[i];
                    if(k>=1)
                        f[1][j][k]=max(f[1][j][k],f[0][j][k-1]+b[i]);
                    if(i-j-k>=1&&i-j-k<=n/2)
                        f[1][j][k]=max(f[1][j][k],f[0][j][k]+c[i]);
                    if(i==n)
                        ans=max(ans,f[1][j][k]);
                }
            swap(f[0],f[1]);
        }
        cout<<ans<<'\n';
        return;
    }
    if(flag1){
        sort(a+1,a+n+1);
        for(int i=n/2+1;i<=n;i++)
            ans+=a[i];
        cout<<ans<<'\n';
        return;
    }
    if(flag2){
        for(int i=1;i<=n;i++)
            g[i]={a[i],b[i]};
        sort(g+1,g+n+1,cmp);
        int cnt1=0,cnt2=0,cnt=0;
        for(int i=1;i<=n&&cnt1<n/2;i++){
            if(g[i].d>g[i].e)
                ans+=g[i].d,cnt1++;
            else if(g[i].d==g[i].e)
                ans+=g[i].d;
            else
                h[++cnt]=g[i];
        }
        sort(h+1,h+cnt+1,cmp2);
        for(int i=1;i<=cnt;i++){
            if(cnt2<n/2)
                ans+=h[i].e;
            else
                ans+=h[i].d;
            if(h[i].e>h[i].d)
                cnt2++;
        }
        cout<<ans<<'\n';
        return;
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
