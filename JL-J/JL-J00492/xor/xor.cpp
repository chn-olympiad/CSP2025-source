#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int a[N];
int vis[N];
int n,k;
int ans=0;
int ansA=1;
int subB1,subB0;
namespace subB{
    void solve(){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(i==0){
                    ans++;
                }
                else{
                    if(a[i]==1&&a[i]==a[i-1]){
                        ans++;
                        i++;
                        i++;
                    }
                }
            }
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
        }
    }
}
namespace subA{

    void solve(){
        if(k==0){
            cout<<n/2;
        }
        else if(k==1){
            cout<<n;
        }
        else{
            cout<<0;
        }
    }

}
namespace sub1{
    void solve(){
        for(int i=0;i<=n;i++){
            for(int j=1;j<=n;j++){
                int cnt=0;
                for(int k=j;k<=min(j+i,n);k++){
                    if(vis[k]==1){
                        j=k;
                        break;
                    }
                    cnt^=a[k];
                }
                if(cnt==k){
                    ans++;
                    for(int k=j;k<=j+i;k++){
                        vis[k]=1;
                    }
                    j=j+i;
                }
            }
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ansA*=a[i];
        if(a[i]==0){
            subB0++;
        }
        if(a[i]==1){
            subB1++;
        }
    }
    if(ansA==1){
        subA::solve();
        return 0;
    }
    if(subB1+subB0==n){
        subB::solve();
        cout<<ans;
        return 0;
    }
    if(n<=5000){
        sub1::solve();
        cout<<ans;
        return 0;
    }
    return 0;
}
