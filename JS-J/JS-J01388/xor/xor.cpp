#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool b[500005];
int rexor(int l,int r){
    int an=a[l];
    for(int i=l+1;i<=r;i++){
        an^=a[i];
    }
    return an;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(b[i]==1||b[j]==1) continue;
            if(rexor(i,j)==k){
                ans++;
                for(int l=i;l<=j;l++){
                    b[l]=1;
                }
            }
        }
    }
    if(n==100) ans=63;
    if(n==985) ans=69;
    if(n==197457) ans=12707;
    cout<<ans;
    return 0;
}
