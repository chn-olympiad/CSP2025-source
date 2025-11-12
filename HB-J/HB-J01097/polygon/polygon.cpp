#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
const int N=5000+5;
const int mod=998244353;
int n,ans,cnt,cnt1;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    cnt=n*(n-1)*(n-2);
    cnt1=6;
    ans+=cnt/cnt1;
    for(int i=4;i<=n;i++){
        cnt*=(n-i+1);
        cnt1*=i;
        ans+=cnt/cnt1;
        ans%=mod;
    }
    cout<<ans%mod;
    fclose(stdin);
    fclose(stdout);
    return 0;
}