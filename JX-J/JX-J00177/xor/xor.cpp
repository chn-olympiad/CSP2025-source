#include<iostream>
using namespace std;
int a[500005];
int solve(int l,int r){
    if(l==r) return a[l];
    int ans=a[l];
    for(int i=l+1;i<=r;i++){
        ans=ans^a[i];
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int so=solve(l,r);
            if(so==k){
                sum++;
                l=r+1;
            }
        }
    }
    cout<<sum;
    return 0;
}

