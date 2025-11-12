#include<bits/stdc++.h>
using namespace std;
long long n,k,p=0;
long long a[60006];
int zhuan(int x){
    long long s=0;
    int i=1;
    while(x!=0){
        s=s+x%2*i;
        x=x/2;
        i=i*10;
    }
    return s;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
     cin>>n>>k;
     for(int i=1;i<=n;i++){
        cin>>a[i];
     }
    if(k==0){
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ans++;
            }
            if(a[i]==1&&a[i+1]==1){
                ans++;
                a[i+1]=-1;
            }
        }
        cout<<ans;
        return 0;
    }
    if(k==1){
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
