#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
const int N=5005;
int n,a[N];
ll kp[5005];
ll df(int k,int s,int maxs,int x){
    if(k>n&&x>=3&&s>maxs*2){
        //cout<<s<<" "<<maxs<<" "<<x<<endl;
        return 1;
    }
    else if(k>n)return 0;
    ll res=0;
    res=(res+df(k+1,s+a[k],a[k],x+1))%mod;
    res=(res+df(k+1,s,maxs,x))%mod;
    //cout<<k<<" "<<s<<" "<<maxs<<" "<<x<<"    "<<res<<endl;
    return res;
}
bool cmp(int a,int b){
    return a>b;
}
ll df2(int k,int s,int maxs,int x){
    if(x>=3&&s>maxs*2){
        if(kp[n-k+1]!=0)return kp[n-k+1];
        ll res=0;
        for(int i=1;i<=n-k+1;i++){
            ll jia=1;
            for(int j=n;j>n-k+1-i;j--)jia=(jia*j)%mod;
            for(int j=2;j<=i;j++)jia/=j;
            res=(res+jia)%mod;
        }
        return kp[n-k+1]=res;
    }
    if(k>n)return 0;
    ll res=0;
    res=(res+df2(k+1,s+a[k],max(maxs,a[k]),x+1))%mod;
    res=(res+df2(k+1,s,maxs,x))%mod;
    //cout<<k<<" "<<s<<" "<<maxs<<" "<<x<<"    "<<res<<endl;
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int cmax=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cmax=max(cmax,a[i]);
    }
    if(cmax==1){
        ll res=0;
        for(int i=3;i<=n;i++){
            ll jia=1;
            for(int j=n;j>n-i;j--)jia=(jia*j)%mod;
            for(int j=2;j<=i;j++)jia/=j;
            res=(res+jia)%mod;
        }
        cout<<res;
        return 0;
    }
    if(n<=20){
        sort(a+1,a+1+n);
        cout<<df(1,0,0,0);
    }
    else{
        sort(a+1,a+1+n,cmp);
        cout<<df2(1,0,0,0);
    }
    return 0;
}
