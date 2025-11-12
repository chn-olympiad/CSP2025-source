#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s=0,maxn,ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l+2;r<=n;r++){
            s=0;
            maxn=-INT_MAX;
            for(int i=l;i<=r;i++){
                s+=a[i];
                maxn=max(maxn,a[i]);
            }
            if(s>maxn*2){
                ans++;
            }
        }
    }
    cout<<(((ans%998)%244)%353);
    return 0;
}
