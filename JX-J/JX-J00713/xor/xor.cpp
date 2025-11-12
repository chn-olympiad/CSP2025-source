#include<bits/stdc++.h>
using namespace std;
long long a[10000001],n,m,k,l,r;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]) {
            l=1;
        }
    }
    if(l==0&&k==0){cout<<n/2;}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
