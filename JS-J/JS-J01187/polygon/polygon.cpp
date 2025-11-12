#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
long long n;
long long a[5005];
int x[20005];
bool cmp(int y,int z){
    return y>z;
}
int n2ncode(int k,int many){
    if(k==n){
        long long sum=0,mx=0,tot=0;
        for(int i=1;i<=n;i++){
             if(x[i]){
                    tot++;
                mx=max(mx,a[i]);
                sum+=a[i];
             }
        }
        if(tot<3){
            return 0;
        }
        if((mx*2)<sum){
            return 1;
        }
        return 0;
    }
    long long ans=0;
    x[k+1]=1;
    ans+=n2ncode(k+1,many+1);
    x[k+1]=0;
    ans+=n2ncode(k+1,many);
    ans%=mod;
    return ans;
}
int howmany[5001];
int superspeed(int k,int many,int sum,int mx){
    if(k>n){
        return 0;
    }
    if(sum>2*mx){
        return howmany[n-k];
    }
    long long ans=0;
    ans+=superspeed(k+1,many+1,sum+a[k+1],mx);
    ans+=superspeed(k+1,many,sum,mx);
    ans%=mod;
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool all1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            all1=0;
        }
    }
    if(all1){
        int ans=0,last=(n*(n-1)/2);
        for(int i=3;i<=n;i++){
            last*=(n-i+1);
            last/=i;
            last%=mod;
            ans+=last;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    if(n<=20){
        cout<<n2ncode(0,0);
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    int ans=0;howmany[1]=1;
    for(int i=2;i<=n;i++){
            howmany[i]=howmany[i-1]*2;
            howmany[i]%=mod;
    }
    for(int i=1;i<=n;i++){
        ans+=superspeed(i,1,a[i],a[i]);
        ans%=mod;
    }
    cout<<ans;


    return 0;
}
