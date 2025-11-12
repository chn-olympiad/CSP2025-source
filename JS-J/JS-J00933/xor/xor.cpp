#include<bits/stdc++.h>
using namespace std;
int n,k,w,ans;
const int maxn=5e5+10;
int a[maxn]={};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int flsg=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)flsg=1;
    }
    if(flsg==0&&k==0){
        cout<<n-n%2;
        return 0;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0)ans++;
            if(a[i]==1&&a[i+1]==1)ans++;
        }
        cout<<ans;
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)ans++;
            if(a[i]==0&&a[i+1]==0)ans++;
        }
        cout<<ans;
    }
    return 0;
}
