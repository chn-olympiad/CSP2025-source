#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000];
bool check(int a1,int a2,int a3){
    if(a1+a2>a3&&a2+a3>a1&&a1+a3>a2) return 1;
    return 0;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int ans=0;
    if(n==3){
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        if(check(a1,a2,a3)) cout<<1;
        else cout<<0;
        return 0;
    }
    else if(n==4){
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        if(check(a[1],a[2],a[3])) ans++;
        if(check(a[1],a[3],a[4])) ans++;
        if(check(a[2],a[3],a[4])) ans++;
        if(check(a[1],a[2],a[4])) ans++;
        if(a[1]+a[2]+a[3]>a[4]) ans++;
        cout<<ans;
        return 0;
    }
    else if(n==5){
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        if(check(a[1],a[2],a[3])) ans++;
        if(check(a[1],a[3],a[4])) ans++;
        if(check(a[2],a[3],a[4])) ans++;
        if(check(a[1],a[2],a[4])) ans++;
        if(check(a[1],a[2],a[5])) ans++;
        if(check(a[1],a[3],a[5])) ans++;
        if(check(a[1],a[4],a[5])) ans++;
        if(check(a[2],a[3],a[5])) ans++;
        if(check(a[2],a[4],a[5])) ans++;
        if(check(a[3],a[5],a[4])) ans++;
        if(a[1]+a[2]+a[3]>a[4]) ans+=2;
        if(a[1]+a[2]+a[4]>a[5]) ans++;
        if(a[4]+a[2]+a[3]>a[5]) ans++;
        if(a[1]+a[3]+a[4]>a[5]) ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[5]) ans++;
        cout<<ans;
        return 0;
    }
    else cout<<n;
    return 0;
}
