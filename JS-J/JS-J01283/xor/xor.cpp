#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i]^a[i-1];
    }
    long long sum=0,p=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j>p;j--){
            if(((a[i])^(a[j-1]))==k){
                p=i;
                sum++;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
