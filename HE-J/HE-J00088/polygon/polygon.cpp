#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
long long cnt;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int len=3;len<=n;len++){
        for(int i=1;i<=n && i+len-1<=n;i++){
            int maxx=0;
            int sum=0;
            for(int j=i;j<=len && j<=n;j++){
                sum+=a[j];
                maxx=max(maxx,a[j]);
            }
            maxx*=2;
            if(sum>maxx){
                cnt++;
            }
        }
    }
    cout<<cnt%mod;
    return 0;
}
