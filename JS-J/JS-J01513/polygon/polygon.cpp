#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005];
long long ans=0,x;
void dfs(int m,int id,long long x){
    if(m==1){
        int i=id+1;
        while(x>a[i]&&i<=n)ans++,i++;
        return;
    }
    for(int i=id+1;i<=n;i++){
        dfs(m-1,i,x+a[i]);
    }

}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)x++;
    }
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
            cout<<1;
            return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }
    else if(x==n){
        for(int i=3;i<n;i++){
            long long sum=1;
            for(int j=n;j>=i;j--)sum*=j;
            for(int j=2;j<=(n-i);j++)sum/=j;
            cout<<sum;
            ans=(ans%mod+sum)%mod;
        }
        ans++;
        cout<<ans%mod;
    }
    else{
        ans=0;
        for(int i=3;i<=n;i++){
            dfs(i,0,0);
            ans%=mod;
        }
        cout<<ans%mod;
    }
    return 0;
}
