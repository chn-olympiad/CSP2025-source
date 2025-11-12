#include <bits/stdc++.h>
using namespace std;
int n,k,a[1005],s[1005],l=0,r,mid,p=-1,ans=0;
int fun(){
    int x=p+1,u=1e9;
    for(int i=x;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==0){
                if(s[j]==k){
                    u=min(u,j);
                }
            }
            else if((s[j]^s[i-1])==k){
                u=min(u,j);
            }
        }
    }
    if(u==1e9){
        return 0;
    }
    p=u;
    return 1;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    r=n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            s[i]=a[i];
        }
        else{
            s[i]=(a[i]^s[i-1]);
        }
    }
    while(l<=r){
        mid=(l+r)>>1;
        p=-1;
        for(int i=0;i<mid;i++){
            if(not(fun())){
                r=mid-1;
                break;
            }
        }
        if(r!=mid-1){
            l=mid+1;
            ans=max(ans,mid);
        }
    }
    cout<<ans;
    return 0;
}
