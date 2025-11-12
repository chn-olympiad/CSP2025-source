#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int T,n,chs[N],num[5],cnt;
using ll=long long;
ll a[N][5],ans,s[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    ans=0;
    for(int i=1;i<=n;++i){
        chs[i]=1;
        if(a[i][chs[i]]<a[i][2]) chs[i]=2;
        if(a[i][chs[i]]<a[i][3]) chs[i]=3;
        ans+=a[i][chs[i]];
    }
    for(int i=1;i<4;++i) num[i]=0;
    for(int i=1;i<=n;++i)
        ++num[chs[i]];
    int Mor=0;
    for(int i=1;i<4;++i)if(num[i]>n/2)
        Mor=i;
    if(Mor==0){cout<<ans<<endl;return ;}
    cnt=0;
    for(int i=1;i<=n;++i)if(chs[i]==Mor){
        int pmax=-1;
        if(Mor!=1&&a[i][1]>pmax) pmax=a[i][1];
        if(Mor!=2&&a[i][2]>pmax) pmax=a[i][2];
        if(Mor!=3&&a[i][3]>pmax) pmax=a[i][3];
        s[++cnt]=-a[i][Mor]+pmax;
    }
    sort(s+1,s+cnt+1,[](int u,int v){return u>v;});
    for(int i=1;i<=num[Mor]-n/2;++i)
        ans+=s[i];
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}