#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,k,sum,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++) cin>>a[i];
    long long l,r;
    l=1,r=n;
    cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        sum^=a[i];
        if(sum==k){
            cnt++;
            sum=0;
        }
    }
    cout<<cnt;
    return 0;
}
