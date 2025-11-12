#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,ans;
long long modnum=998244353;

void dfs(long long k,long long maxx,long long sum){
    for (long long i=k+1;i<=n;i++){
        long long tmp=maxx;
        maxx=max(maxx,a[i]);
        sum+=a[i];
        if (sum>2*maxx){
            ans++;
            ans%=modnum;
        }
        dfs(i,maxx,sum);
        sum-=a[i];
        maxx=tmp;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (long long i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=0;
    dfs(0,0,0);
    cout<<ans%modnum<<endl;
    return 0;
}
