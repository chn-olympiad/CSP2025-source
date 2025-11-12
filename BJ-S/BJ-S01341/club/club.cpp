#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int N=1e5+5;
struct data{ll a, b, c, t;}a[N];

ll T, n, ans;

void dfs(int d,int ka,int kb,int kc,ll sum){
    if(ka>n/2||kb>n/2||kc>n/2) return;
    if(d>n){
        ans=max(ans, sum);
        return;
    }
    dfs(d+1, ka+1, kb, kc, sum+a[d].a);
    dfs(d+1, ka, kb+1, kc, sum+a[d].b);
    dfs(d+1, ka, kb, kc+1, sum+a[d].c);
}

bool cmpa(data x, data y){
    return x.a>y.a;
}
bool cmpt(data x, data y){
    if(x.t!=y.t) return x.t>y.t;
    return x.b<y.b;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>T;
    int fb=1, fc=1;
    while(T--){
        cin>>n;
        ans=0; fb=fc=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].b!=0) fb=0;
            if(a[i].c!=0) fc=0;
        }
        if(n<=10){
            dfs(1, 0, 0, 0, 0);
            cout<<ans<<endl;
            continue;
        }
        if(fb&&fc){
            sort(a+1, a+n+1, cmpa);
            for(int i=1;i<=n/2;i++)
                ans+=a[i].a;
            cout<<ans<<endl;
            continue;
        }
        if(fc){
            for(int i=1;i<=n;i++)
                a[i].t=a[i].a-a[i].b;
            sort(a+1, a+n+1, cmpt);
            for(int i=1;i<=n/2;i++)
                ans+=a[i].a;
            for(int i=n/2+1;i<=n;i++)
                ans+=a[i].b;
            cout<<ans<<endl;
        }
    }
    return 0;
}
