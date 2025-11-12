#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500020],xr[500020],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0)
        {
            xr[i]=a[i];
        }
        else{
            xr[i]=xr[i-1]^a[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long long x;
            if(j==i){
                x=a[i];
            }
            else{
                if(i!=0)
                    x=xr[j]^xr[i-1];
                else
                    x=xr[j];
            }
            if(x==k){
                ans++;
            }
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
