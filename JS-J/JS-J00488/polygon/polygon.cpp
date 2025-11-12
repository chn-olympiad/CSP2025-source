#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5009];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int p=998244353;

    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int sum=0;
    for(int i=n;i>=3;i--){
        for(int j=i-1;j>=2;j--){
                if(a[j]+a[j-1]<=a[i]) break;
            for(int k=j-1;k>=1;k--){
                if(a[j]+a[k]>a[i]){
                    sum=(sum+1)%p;
                }
                else break;
            }
        }
    }
    cout<<sum%p;
    return 0;
}
