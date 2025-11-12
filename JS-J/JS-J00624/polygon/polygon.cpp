#include<bits/stdc++.h>
#define FUCK using
#define YOU namespace
#define CCF std;
FUCK YOU CCF
#define ll long long
bool flag=true;
int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,ans;
    cin>>n;
    int a[6000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n=3){
        if(a[0]+a[1]>a[2]&&a[1]+a[2]>a[0]&&a[0]+a[2]>a[1]){
            ans=1;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=1){
            flag=false;
            exit(0);
        }
    }
    if(flag){
        for(int i=3;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                    ans+=j;
            }
        }
    }
    cout<<ans%998244353<<endl;

    return 0;
}
