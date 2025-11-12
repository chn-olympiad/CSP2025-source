#include<iostream>
#include<cstdio>
using namespace std;
long long n,k;
int a[500000+5];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            cnt++;
    }
    if(k==1)
        cout<<cnt;
    else
        cout<<n-cnt;
    return 0;
}
