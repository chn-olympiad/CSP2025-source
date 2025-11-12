#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100],b[100100];
unsigned long long ans;
void dfs(int i,long long sum,int maxn,int cnt,int k){
    if(cnt==k){
        if(sum>2*maxn)ans=(ans+1)%998244353;
        return;
    }
    if(cnt>k||i>n){
        return;
    }
    dfs(i+1,sum+a[i],max(maxn,a[i]),cnt+1,k);
    dfs(i+1,sum,maxn,cnt,k);
    return;
}
int main()
{
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    int maxn=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
       for(int i=3;i<=n;i++){
            int a=i,b=n;
            unsigned long long sum=1;
            for(int i=b;i>=b-a+1;i--){
                sum*=i;
            }
            for(int i=a;i>=1;i--){
                sum/=i;
            }
            ans=(ans+sum)%998244353;
       }
       cout<<ans%998244353;
        return 0;
    }
    for(int i=3;i<=n;i++){
        dfs(1,0,0,0,i);
    }
    cout<<ans%998244353;
    return 0;
}
