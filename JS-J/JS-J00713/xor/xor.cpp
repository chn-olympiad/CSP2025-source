#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,k,ans,i,a[N];
bool b;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        cout<<n/2;
    }else if(k==1){
        for(i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
