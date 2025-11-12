#include<bits/stdc++.h>
using namespace std;
int t=1,ji;
int a[5005],maxa,ans;
const int mod=998244353;
int aaa(int n,int m){
    for(int i=1;i<=m;i++){
        t*=(n-ji);
        ji++;
    }
    return t;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    if(n==3){
        maxa=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>2*maxa) cout<<"1";
        else cout<<"0";
    }
    else if(maxa==1){
        for(int i=1;i<=n;i++){
            ans+=aaa(n,i);
            ans%=mod;
        }
        cout<<ans;
    }
    else{
        if(n>=4&&a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
                ans++;
                ans%=mod;
        }
        if(n>=4&&a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))){
                ans++;
                ans%=mod;
        }
        if(n>=4&&a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))){
                ans++;
                ans%=mod;
        }
        if(n>=4&&a[2]+a[3]+a[4]>2*max(a[2],max(a[3],a[4]))){
                ans++;
                ans%=mod;
        }
        if(n>=4&&a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))){
                ans++;
                ans%=mod;
        }
        if(n>=5&&a[1]+a[2]+a[3]+a[5]>2*max(a[1],max(a[2],max(a[3],a[5])))){
                ans++;
                ans%=mod;
        }
        if(n>=5&&a[1]+a[3]+a[4]+a[5]>2*max(a[1],max(a[5],max(a[3],a[4])))){
                ans++;
                ans%=mod;
        }
        if(n>=5&&a[2]+a[3]+a[4]+a[5]>2*max(a[2],max(a[3],max(a[4],a[5])))){
                ans++;
                ans%=mod;
        }
        if(n>=5&&a[1]+a[2]+a[3]+a[4]+a[5]>2*max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))){
                ans++;
                ans%=mod;
        }
        cout<<ans;
    }

    return 0;
}
