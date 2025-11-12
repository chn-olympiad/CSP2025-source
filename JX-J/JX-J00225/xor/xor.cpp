#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10005],b[10005],ans;

int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1){
            b[i]=b[i-1]&a[i];
        }
    }
    if(k==0||k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==k)ans++;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
