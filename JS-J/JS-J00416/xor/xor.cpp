#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
        cout<<n/2;
        return 0;
    }
    else if(k<=1){
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1&&a[i+1]==0){
                ans++;
                i+=1;
            }
            else if(a[i]==0&&a[i+1]==1){
                ans++;
                i+=1;
            }
            else if(a[i]==1&&a[i+1]==1&&a[i+2]==1){
                ans++;
                i+=2;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}