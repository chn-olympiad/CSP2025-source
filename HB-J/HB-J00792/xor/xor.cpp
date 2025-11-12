#include<bits/stdc++.h>
using namespace std;
int n,k;
const int mx=5*1E5+5;
int a[mx];
int cnt;
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(k==0&&a[1]<=1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)cnt++;
        }
        cout<<max(n/2,n-cnt);
        return 0;
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)cnt++;
        }
        cout<<cnt;                                                                                                                                                                                                                                                 cnt;
        return 0;
    }
    int t=0;
    for(int i=1;i<=n;i++){
        t=t^a[i];
        if(t==k||a[i]==k){
            t=0;
            ans++;
        }

    }
    cout<<ans;
    return 0;
}
