#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,a[N],k,y[N],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(i==1) y[i]=a[i];
        else y[i]=y[i-1]^a[i];
    }
        for(long long l=1;l<=n;l++){
            for(long long r=l;r<=n;r++){
                long long x=y[r]^y[l-1];
                if(x==k){
                    cnt++;
                    l=r;
                    break;
                }
            }
        }
    cout<<cnt;
    return 0;
}
