#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n;
long long a[500005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r=3;
    long long s=0;
    while(l<=n){
        long long sum=0;
        long long maxn=0;
        for(long long i=1;i<=n;i++){
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }
        if(sum>=maxn*2){
            s++;
            l++;
        }
    }
    cout<<s;
    return 0;
}
