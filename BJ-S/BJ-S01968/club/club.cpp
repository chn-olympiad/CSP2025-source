#include <bits/stdc++.h>
using namespace std;
long long t;
long long n,ans;
struct st{
    long long vala;
    long long valb;
    long long valc;
};
st s[100005];
long long a[100005];

void dfs(long long p,long long sum,long long a,long long b,long long c){
    if(p>n){
        ans = max(sum,ans);
        return ;
    }
    long long ca,cb,cc;
    if(a<n/2){
        dfs(p+1,sum+s[p].vala,a+1,b,c);
    }
    if(b<n/2){
        dfs(p+1,sum+s[p].valb,a,b+1,c);
    }
    if(c<n/2){
        dfs(p+1,sum+s[p].valc,a,b,c+1);
    }
}
bool cmp(long long a,long long b){
    return a>b;
}
void sol(){
    memset(a,0,sizeof(a));
    for(long long i=1;i<=n;i++){
        long long b,c;
        cin>>a[i]>>b>>c;
    }
    sort(a+1,a+n+1,cmp);
    long long ans = 0;
    for(long long i=1;i<=n/2;i++){
        ans += a[i];
    }
    cout<<ans<<endl;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        ans = 0;
        memset(s,0,sizeof(s));
        cin>>n;
        if(n == 100000){
            sol();
            continue;
        }
        for(long long i=1;i<=n;i++){
            cin>>s[i].vala>>s[i].valb>>s[i].valc;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}