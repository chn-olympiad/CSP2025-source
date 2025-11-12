#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("employ.in","r",stdin);
        freopen("employ.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
using ll=long long;
const int N=5e2+11,S=(1<<18)+5,Q=998244353;
int n,m;
int a[N],c[N];
int cnt[S];
ll f[S][N];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        char c; cin>>c;
        a[i]=c-'0';
    }
    for(int i=0;i<n;i++) cin>>c[i];
    int U=(1<<n)-1;
    for(int s=1;s<=U;s++) cnt[s]=cnt[s>>1]+(s&1);
    f[0][0]=1;
    for(int s=1;s<=U;s++) {
        for(int i=0;i<=cnt[s];i++) {
            for(int j=0;j<n;j++)
                if(s>>j&1) {
                    if(!a[cnt[s]]) {
                        if(i>=1) (f[s][i]+=f[s&~(1<<j)][i-1])>=Q?f[s][i]-=Q:0;
                    }
                    else {
                        if(i<c[j]) (f[s][i]+=f[s&~(1<<j)][i])>=Q?f[s][i]-=Q:0;
                        else if(i!=c[j]&&i>=1) (f[s][i]+=f[s&~(1<<j)][i-1])>=Q?f[s][i]-=Q:0;
                    }
                }
        }
    }
    ll rs=0;
    for(int i=0;i<=n-m;i++)
        (rs+=f[U][i])>=Q?rs-=Q:0;
    cout<<rs<<'\n';
    return 0;
}