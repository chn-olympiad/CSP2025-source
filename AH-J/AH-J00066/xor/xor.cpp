#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],x,sum,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    x=a[1];
    for(int i=2;i<=n;i++)
    {
        if(x==k) sum++,x=a[i];
        else x^=a[i];
        if(a[i]==k) ans++;
    }
    if(x==k) sum++;
    cout<<max(ans,sum);
    return 0;
}
