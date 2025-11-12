#include<bits/stdc++.h>
using namespace std;
int numm[500005],xorr[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k>>numm[1];
    xorr[1]=numm[1];
    for(int i=2;i<=n;i++){
        cin>>numm[i];
        xorr[i]=xorr[i-1]^numm[i];
    }
    int pos=n+1,ans=0;
    for(int i=1;i<=n;i++){//zuozhizhen
       for(int j=i;j<=n;j++){//youzhizhen
            if((int)(xorr[i]^numm[j])==k){
                if(j<=pos){
                    pos=j;
                    ans++;
                }
            }
       }
    }
    cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);

}
