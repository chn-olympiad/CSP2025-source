#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
bool b[5001];
int ans;
void f(int x){
    if(x==n+1){
        int tot=0,ma=0;
        for(int i=1;i<=n;i++){
            if(b[i]){
                tot+=a[i];
                ma=max(ma,a[i]);
            }
        }
        if(tot>ma*2){
            ans++;
        }
        ans%=(2*998244353);
        return;
    }
    f(x+1);
    b[x]=true;
    f(x+1);
    b[x]=false;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f(0);
    cout<<ans/2;
}
