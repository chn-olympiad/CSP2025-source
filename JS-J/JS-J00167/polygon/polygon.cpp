#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],n,ma=0;
long long ans=0,p=998244353;
void dfs(int i,int cnt,int maxx,int sum){
    if(i==n+1){
        if(cnt>=3 and sum>maxx*2)
            ans++;
        return;
    }
    dfs(i+1,cnt+1,max(maxx,b[i]),sum+b[i]);
    if((n-i)>=(3-cnt))
        dfs(i+1,cnt,maxx,sum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
    }
    if(ma==1){
        long long num=0;
        for(int k=3;k<=n;k++){
            int i;
            if(k>n/2)
                i=n-k;
            else
                i=k;
            long long N=1,M=1;
            for(int j=n;j>=n-i+1;j--)
                N*=j;
            for(int j=1;j<=i;j++)
                M*=j;
            num=(num+(N/M)%p)%p;
        }
        cout<<num;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=a[n-i+1];
    for(int i=1;i<=n;i++)
        a[i]=b[i];
    dfs(1,0,0,0);
    cout<<ans%p;
    return 0;
}
