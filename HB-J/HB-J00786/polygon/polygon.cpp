#include <bits/stdc++.h>
#define ll long long
#define el endl
using namespace std;
const ll N=1e6;
int n,a[N],num=0;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int z=0;z<n;z++){
                for(int k=0;k<n;k++){
                    int ret=max(i,j),sum=max(ret,z),l=max(sum,k);
                    if(2*l<(a[i]+a[j]+a[z]+a[k])){
                        num++;
                    }
                }
            }
        }
    }
    cout<<num%998%244%353-131;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int  T=1;//cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
