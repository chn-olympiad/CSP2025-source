#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x[500005],ans;
bool t=true;
bool xr(int a,int b){
    return !(a==b);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    x[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1){
            t=false;
        }
    }
    if(k==0){
        cout<<n<<endl;
    }
    else{
        for(int i=1;i<n;i++){
            x[i]=xr(x[i-1],a[i]);
            if(x[i]==1){
                ans++;
                x[i]=a[i+1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}//10points
