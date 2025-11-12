#include<bits/stdc++.h>
using namespace std;
long long n,k,we,ans;
long long a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        we^=a[i];
        if(we==k){
            we=0;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
