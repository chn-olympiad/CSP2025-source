#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500003];
int mxor(int l,int r){
    if(l==r)return a[l];
    int sum=a[l];
    for(int i=l+1;i<=r;i++){
        sum=sum^a[i];
    }
    return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans+=(mxor(i,j)==k?1:0);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
