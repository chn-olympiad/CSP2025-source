#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],ans,x[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    //cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<" "<<i<<endl;
        x[i]=x[i-1]^a[i];
        //cout<<" "<<x[i]<<endl;
    }
    /*for(int i=1;i<=n;i++){
        x[i]=x[i-1]^a[i];
    }*/
    int l=1,r=1,id;
    while(l<=n&&r<=n){
        id=n+1;
        for(l;l<min(id,n);l++){
            for(r=l;r<=min(id,n);r++){
                //cout<<l<<" "<<r<<endl;
                if((x[r]^x[l-1])==k){
                    //cout<<l<<" "<<r<<" "<<x[l-1]<<" "<<x[r]<<" "<<(x[l-1]^x[r])<<endl;
                    id=min(id,r);

                }
            }
        }
        if(id==n+1)break;
        l=id+1;
        //cout<<id<<endl;
        ans++;
    }

    cout<<ans;
    return 0;
}
