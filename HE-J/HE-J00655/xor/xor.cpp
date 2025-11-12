#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum1,ans,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    bool f=1;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]>1) f=0;
        if (a[i]==1) sum1++;
        if (a[i]==k) sum++;
    }
    if (f){
        if (k==1){
            cout << sum1;
        }
        else{
            ans+=n-sum1;
            sum1=0;
            for (int i=1;i<=n;i++){
                if (a[i]==1){
                    sum1++;
                    ans+=(sum1+1)%2;
                }
                else sum1=0;
            }
            cout << ans;
        }
    }
    else{
        cout << sum;
    }
    return 0;
}
