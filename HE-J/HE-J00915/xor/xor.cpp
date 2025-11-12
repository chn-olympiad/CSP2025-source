#include <bits/stdc++.h>
using namespace std;
long long xulie[10000000];
long long n,k,r;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>xulie[i];
        }
        if(n==2) cout<<max(xulie[1],xulie[2]);
        if(k==1){
           for(int i=1;i<n;i++){
                long long y=xulie[i]^xulie[i+1];
            r=max(r,y);
        }
        }else if(k==0){
            for(int i=1;i<=n;i++){
            r=max(r,xulie[i]);
        }
        }
      cout<<r;
    return 0;
}
