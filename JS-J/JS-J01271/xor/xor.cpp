#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int a,b;
};
int a[500005];
int sum[500005];
int ans=0;
int n,k;
node fun(int l,int r,bool flag){
    if(l>r){
        return {l,r};
    }
    else if(l==r){
        if(a[l]==k){
            ans++;
            return {l-1,r+1};
        }
        else{
            return {l,r};
        }
    }
    else if(l+1==r){
        if(a[l]^a[r]==k){
            ans++;
            return {l-1,r+1};
        }
        else{
            return {l,r};
        }
    }
    int mid=(r+l)/2;
    node s1=fun(l,mid,0);
    node s2=fun(mid+1,r,1);
    int k1=s1.b,k2=s2.a;
    while(k1<=k2){
        if(sum[k2]^sum[k1-1]==k){
            ans++;
            break;
        }
        k1++;
        if(k1>k2){
            break;
        }
        if(sum[k2]^sum[k1-1]==k){
            ans++;
            break;
        }
        k2--;
        if(k1>k2){
            break;
        }
        if(sum[k2]^sum[k1-1]==k){
            ans++;
            break;
        }
    }
    return {s1.a-1,s2.b+1};
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1];
    sum[1]=a[1];
    int xxx=0;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
        xxx=max(xxx,a[i]);
    }
    if(k==0&&xxx==1){
        cout<<n/2;
        return 0;
    }
    fun(1,n,0);
    cout<<ans;
    return 0;
}
