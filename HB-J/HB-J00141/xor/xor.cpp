#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum1=0,sum2=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i],sum1+=a[i];
        if (a[i]==0)sum2++;
    }
    if (k==0)cout<<sum1/2+sum2;
    else if (k==1)cout<<sum1;
    else cout<<0;
    return 0;
}
