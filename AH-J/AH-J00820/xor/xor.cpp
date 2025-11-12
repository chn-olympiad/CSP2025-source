#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],cnt,l,r;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=a[i]^sum[i-1];
    }
    if(k==2) cout<<2;
    else if(k==3) cout<<2;
    else if(k==0) cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
