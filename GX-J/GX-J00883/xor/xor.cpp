#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],m;
int main(){
    freopen("xor1.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            m=m+1;
        }
    }
    cout<<m;
    return 0;
}
