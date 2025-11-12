#include<iostream>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long i,j,n,a[10001];
    cin>>i>>j;
    n=i;
    for(i=1;i<=n;++i)
        cin>>a[i];
    cout<<a[1];
    return 0;
}
