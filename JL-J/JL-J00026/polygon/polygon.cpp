#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
long long ans=0;
int n,m;
const long long mod=998244353;
bool f(int a,int b){
    return a>b;
}
int find(int x){
    int r=1,l=n,m=(r+l)/2;
    while(r<m||r>n||l<1){
        m=(r+l)/2;
        if(b[m]<=x) r=m;
        else l=m;
    }
    return m;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=3;i<=n;i++){
        int w=find(a[i]);
        ans+=n-w;
        for(int j=w;j<=n;j++){
            int v=find(b[j]-a[i]);
            ans+=j-v;
        }
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
