#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],l,ans;
int main(){
    freopen("xor.in","r",stdin);
    freoprn("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    b[0]=0;
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]^a[i];
    }
    l=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=l;j--){
            int x=b[i]^b[j];
            if(x==k){
                l=i;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
