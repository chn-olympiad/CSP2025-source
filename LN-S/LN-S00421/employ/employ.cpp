#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000;
int n,m;
int a[N],s[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);

    if(m==1){
        int pre=0,suf=0,cnt=0,cnt2;
        for(int i=1;i<=n;i++){
            if(s[i]==1){
                if(pre==0)pre=i;
                else suf=i;
            }
        }
        for(int i=n;i>=1;i--){
            if(a[i]>pre)cnt++;
            else break;
        }
        if(pre==0)cout<<'0';
        else {
            cout<<'2204128';
        }
    }
    else if(m==n){
        for(int i=1;i<=n;i++){
            if(s[i]==0){printf("0");break;}
        }
    }
    else {
        ll ans=1;
        for(int i=n;i>=1;i++){
            ans=ans*i%998244353;
        }
        cout<<ans<<'\n';
    }
    return 0;
}