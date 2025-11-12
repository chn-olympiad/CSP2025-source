#include <bits/stdc++.h>
using namespace std;
const int N=5e3+14,MOD=998244353;
long long ans;
int n,a[N];
void dfs(int r,int ma,int s,int g){
    if(r>n)return;int k=ma;
    s+=a[r];g++;ma=a[r];
    if(s>2*ma&&g>=3)ans=(ans+1)%MOD;
    dfs(r+1,ma,s,g);
    s-=a[r];g--;ma=k;
    dfs(r+1,ma,s,g);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;return 0;
    }else if(n==3){
        int x,y,z;
        cin>>x>>y>>z;
        int ma=max(x,max(y,z));
        if(x+y+z>2*ma){
            cout<<1;return 0;
        }
        cout<<0;return 0;
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
