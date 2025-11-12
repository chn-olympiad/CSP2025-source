#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int mod=998244353;
long long qp(long long x,long long y){
    long long ans=1;
    while(y){
        if(y%2==1){
            ans=ans*x%mod;
        }
        x=x*x%mod;
        y/=2;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==1||n==2){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(a[n]==1){
        long long s=n-1;
        long long ans=qp(2,n)-1-n-n*(n-1)/2;
        cout<<ans;
        return 0;
    }
    long long ans=0;
    for(int i=3;i<=n;i++){
        int j=1;
        while(a[i-1]+a[j]<=a[i]&&j<=i-2){
            j++;

        }if(j!=i-1){long long x=i-j-1;
                int sum=qp(2,x)-1;
                ans=(ans+sum)%mod;
}

        }
    cout<<ans;
    return 0;
}
