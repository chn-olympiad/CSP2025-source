#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sumx[500005],ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sumx[i]=sumx[i-1]^a[i];
    }
    int l=1,r=1;
    for(r=1;r<=n;r++){
        int tl=l;
        while((sumx[r]^sumx[l-1])!=k&&l<r) l++;
        if((sumx[r]^sumx[l-1])==k){
                ans++;
                l=r+1;
        }
        else if(l==r) l=tl;
    }
    cout<<ans;
    return 0;
}
