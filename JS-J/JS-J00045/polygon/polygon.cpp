#include<bits/stdc++.h>
#define N 510
#define mod 998244353
using namespace std;
long long n;
long long a[N];
long long ans=0;
long long maxx=-1;
void change(long long x,long long n){
    unsigned long long cnt1=1,cnt2=1;
    long long y=n-x;
    if(x>y)swap(x,y);
    for(int i=y;i<=n;i++){
        cnt1*=i;
        cnt1%=mod;
    }
    for(int i=1;i<=x;i++){
        cnt2*=i;
        cnt2%=mod;
    }
    ans+=cnt1/cnt2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=3){
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1])
            cout<<1;
        else cout<<0;
    }
    else{
        for(int i=3;i<=n;i++){
            change(i,n);
        }
        cout<<ans%998244353;
    }
    return 0;
}
