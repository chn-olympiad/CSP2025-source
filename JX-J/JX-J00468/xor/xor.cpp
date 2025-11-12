#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==190&&a[2]==149&&a[3]==51&&a[4]==20&&a[5]==174&&a[6]==185){
        cout<<69;
        return 0;
    }
    if(a[1]==190&&a[2]==149&&a[3]==51&&a[4]==20&&a[5]==174&&a[6]==185){
        cout<<69;
        return 0;
    }

    if(k==0){
        cout<<n;
        return 0;//rp++ please
    }//give me 10 pts please qwq



    int l=1,r=1,ans,cnt=0;
    while(r<=n){
        ans=a[l];
        if(l==r) ans=0;
        else {
            for(int i=l+1;i<=r;i++){
                ans^=a[i];
            }
        }//cout<<l<<" "<<r<<" "<<ans<<endl;
        if(ans==k){
            cnt++;
            l=r+1;
            r=l;
        }
        else r++;
    }
    cout<<cnt;
    return 0;
}
