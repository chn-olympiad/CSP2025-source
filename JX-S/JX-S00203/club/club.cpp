#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 1e9
#define LLINF 1e18
#define ll long long
#define Mod 998244353
#define FILE1(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define FILE2(x) freopen(x".in","r",stdin),freopen(x".ans","w",stdout)
#define FILE3(x) freopen(x".in","r",stdin)
#define N 100005
using namespace std;
int read(){
    int x=0,f=1,ch=getchar();
    for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
    return x*f;
}
int T,n,ans,a[N][3],d[N];
vector<int>vec[3];
int work(int t){
    int sum=0;
    for(int i=1;i<=n;++i) sum+=a[i][t];
    for(int i=1;i<=n;++i){
        d[i]=-INF;
        for(int j=0;j<3;++j){
            if(j==t) continue;
            d[i]=max(d[i],a[i][j]-a[i][t]);
        }
    }
    sort(d+1,d+n+1),reverse(d+1,d+n+1);
    for(int i=1;i<=n/2;++i) sum+=d[i];
    return sum;
}
void solve(){
    n=read(),ans=0;
    for(int i=1;i<=n;++i) for(int j=0;j<3;++j) a[i][j]=read();
    for(int i=0;i<3;++i) ans=max(ans,work(i));
    for(int i=0;i<3;++i) vector<int>().swap(vec[i]);
    for(int i=1;i<=n;++i){
        int mx=0;
        for(int j=0;j<3;++j) mx=max(mx,a[i][j]);
        for(int j=0;j<3;++j){
            if(a[i][j]==mx){
                vec[j].push_back(i);
                break;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;++i){
        int mx=0;
        for(int j=0;j<3;++j) mx=max(mx,a[i][j]);
        res+=mx;
    }
    if((int)vec[0].size()<=n/2 && (int)vec[1].size()<=n/2 && (int)vec[2].size()<=n/2) ans=max(ans,res);
    else{
        int t=0;
        for(int i=1;i<3;++i) if((int)vec[i].size()>(int)vec[t].size()) t=i;
        int cnt=(int)vec[t].size();
        for(int j=0;j<(int)vec[t].size();++j){
            int i=vec[t][j];
            for(int k=0;k<3;++k){
                if(k==t) continue;
                if(a[i][t]==a[i][k]){
                    --cnt;
                    break;
                }
            }
        }
        if(cnt<=n/2) ans=max(ans,res);
    }
    printf("%d\n",ans);
}
int main(){
    FILE1("club");
    T=read();
    while(T--) solve();
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/