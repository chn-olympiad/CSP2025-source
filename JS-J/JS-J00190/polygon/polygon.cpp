#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod=998244353;

int n;
int a[5005],b[5005];
bool f1=1;
ll ans=0;
ll tmp=0;

void dfs(int p,int fi,ll now,ll ma,int cnt){


    if(p==fi+1)return ;

    if(b[fi]-now <= ma)return ;
    else tmp=(tmp+1)%mod;
    if(cnt==fi-2)return ;

    for(int i=p+1;i<=fi+1;i++){
        if(i!=fi+1) dfs(i,fi,now+a[i],ma,cnt+1);
        else dfs(i,fi,now,ma,cnt+1);
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    if(a[n]!=1)f1=0;
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];

    if(f1){
        int tmp=1;
        for(int i=3;i<=n;i++){
            ans=(ans+tmp)%mod;
            tmp*=2;
            tmp%=mod;
            if(tmp==0)tmp=1;
        }
        cout << ans;
        return 0;
    }

    for(int i=3;i<=n;i++){
        int maxx=a[i];
        if(b[i-1]<=maxx)continue;
        tmp=0;
        dfs(0,i-1,0,maxx,0);
        ans=(ans+tmp)%mod;

    }

    cout << ans;
    return 0;
}
