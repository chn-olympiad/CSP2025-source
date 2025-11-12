#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],s[5005],c[1001][1001],ans;
long long dfs(long long idx,long long sum,int r){
    if(sum<a[idx]&&r>=3)
        ++ans;
    for(int i=idx+1;i<=n;i++)
        dfs(i,sum+a[idx],r++);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    for(int i=0;i<=1000;i++){c[i][0]=1;c[i][i]=1;}
    for(int i=1;i<=1000;i++)
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    cin>>n;bool A=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)A=0;
    }
    sort(a+1,a+n+1);

    if(A){
        for(int i=2;i<n;i++)
            ans=(ans+(n-i))%mod;
        cout<<ans<<endl;
        return 0;
    }
    if(n<=500){

        for(int i=1;i<=n-2;i++){
            dfs(i,0,1);
        }
        cout<<ans;
        return 0;
    }

    long long ans=0;
    for(int l=3;l<=n;l++){
        char ch='a'+l-3;
        cout<<ch<<endl;
        for(int t=1;t<=l-2;t++){
            int x=a[l]-a[l-t];
            int idx=upper_bound(a+1,a+l+1,x)-a;
            int k=l-t-idx;
            cout<<l-t<<" "<<idx<<" "<<k<<" ";
            long long ansx=0;
            for(int i=1;i<=k;i++)
                ansx=(ansx+c[k][i])%mod;
            cout<<ansx<<endl;
            ans=(ans+ansx)%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
