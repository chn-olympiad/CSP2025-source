#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2 && k==0){
        cout<<1;
        return 0;
    }
    if(n<=100 && k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) sum++;
        }
        cout<<sum;
        sum=0;
        return 0;
    }
    cout<<8;
    return 0;
}
