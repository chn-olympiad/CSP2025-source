#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int T,n,m;
int ans;
void doit(int u,int sum,int sum0,int sum1,int sum2){
    if(u==n+1){
        ans=max(ans,sum);
        return ;
    }
    if(sum0!=m)doit(u+1,sum+a[u],sum0+1,sum1,sum2);
    if(sum1!=m)doit(u+1,sum+b[u],sum0,sum1+1,sum2);
    if(sum2!=m)doit(u+1,sum+c[u],sum0,sum1,sum2+1);

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
            ans=0;
        cin>>n;
        m=n>>1;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        doit(1,0,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}
