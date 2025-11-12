#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,flag,ans;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=1;
    }
    if(flag==0){
        cout<<n/2;
    }
    else if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0) ans++;
            if(a[i]==1&&a[i-1]==1){
                ans++;
                a[i]=2;a[i-1]=2;
            }
        }
    }
    else if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) ans++;
        }
    }
    cout<<ans;
    return 0;
}
