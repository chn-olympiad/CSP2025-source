#include<bits/stdc++.h>
using namespace std;
const int INF=998244353;
int n,a[5005],t[5005],s[5005];
bool v[5005];
long long ans=0;
int f(int siz,int x){
    int ans=0;
    for(int i=x+1;i<=n;i++){
        if(!v[i]){
            if(a[i]<siz)ans++;
            v[i]=true;
            ans+=f(siz+a[i],i);
            v[i]=false;
        }
        ans%=INF;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1],t[i]+=t[i-1];
    if(t[1]==n){
        long long s=n*(n-1);
        for(int i=3;i<=n;i++){
            s=s*(n-i+1)%INF;
            ans+=s/i;
            ans%=INF;
        }
    }else{
        sort(a+1,a+1+n);
        for(int i=1;i<n-1;i++){
            v[i]=true;
            for(int j=i+1;j<n;j++){
                v[j]=true;
                ans+=f(a[i]+a[j],j);
                v[j]=false;
            }
            v[i]=false;
        }
    }
    cout<<ans;
    return 0;
}

