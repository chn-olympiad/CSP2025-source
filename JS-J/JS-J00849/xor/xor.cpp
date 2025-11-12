#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
long long s[500010];

long long r,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    s[0]=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    r=0,cnt=0;
    for(long long i=1;i<=n;i++){
        for(long long j=i;j>r;j--){
            long long k1=s[i]^s[j-1];
            if(k1==k){
                cnt++;
                r=i;
            }
        }
    }
    cout<<cnt;
    return 0;
}
