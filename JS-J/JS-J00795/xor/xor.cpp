#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            ans+=a[i];
        }
        cout<<ans;
    }
    else{
        int len=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1)len++;
            else{
                ans+=len/2+1;
                len=0;
            }

        }
        cout<<ans;
    }

    return 0;
}
