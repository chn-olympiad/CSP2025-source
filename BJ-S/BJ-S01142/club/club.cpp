#include <bits/stdc++.h>
using namespace std;
long long t,n,a[100001],b[100001],c[100001],dp[201][201][201],ans,cnta,cntb,cntc;
bool cmp(long long x,long long y){
    return x>y;
}
void dfs(long long s,long long num,int na,int nb,int nc){
    if(s>n){
        ans=max(ans,num);
        return ;
    }
    if(na<n/2)dfs(s+1,num+a[s],na+1,nb,nc);
    if(nb<n/2)dfs(s+1,num+b[s],na,nb+1,nc);
    if(nc<n/2)dfs(s+1,num+c[s],na,nb,nc+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]==0)cnta++;
             if(b[i]==0)cntb++;
              if(c[i]==0)cntc++;
        }
        if(cnta==n&&cntb==n){
            sort(c+1,c+n+1,cmp);
            long long ans=0;
            for(int i=1;i<=n/2;i++)ans+=c[i];
            cout<<ans<<endl;
        }
        else if(cntc==n&&cntb==n){
            sort(a+1,a+n+1,cmp);
            long long ans=0;
            for(int i=1;i<=n/2;i++)ans+=a[i];
            cout<<ans<<endl;
        }
        else if(cntc==n&&cnta==n){
            sort(b+1,b+n+1,cmp);
            long long ans=0;
            for(int i=1;i<=n/2;i++)ans+=b[i];
            cout<<ans<<endl;
        }
        else{
       dfs(1,0,0,0,0);
       cout<<ans<<endl;}
    }
    return 0;
}
