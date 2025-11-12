#include <bits/stdc++.h>
using namespace std;
int a[5005],sum[5005];
int n;
bool cmp(int x,int y){
    return x>y;
}
int polygon(int maxa,int id,int usesum){
    if(usesum>maxa){
        int ans=1;
        for(int k=1;k<=n-id;k++){
            ans*=2;
            ans%=998224353;
        }
        return ans;
    }
    if(sum[id]<=maxa-usesum)return 0;
    if(id==n-1)return 1;
    return (polygon(maxa,id+1,usesum)+polygon(maxa,id+1,usesum+a[id]))%998244353;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    if(n<3){
        cout << 0;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    if(a[0]==1){
        int all=1,b;
        for(int i=1;i<=n;i++){
            all*=2;
            all%=998244353;
        }
        b=n*(n-1)/2+n+1;
        if(all>=b)cout << all-b;
        else cout << all+998244353-b;
    }
    for(int i=n-1;i>=0;i--){
        sum[i]=sum[i+1]+a[i];
    }
    int all=0;
    for(int i=0;i<=n-3;i++){
        all+=polygon(a[i],i+1,0);
        all%=998244353;
    }
    cout << all;
    return 0;
}
