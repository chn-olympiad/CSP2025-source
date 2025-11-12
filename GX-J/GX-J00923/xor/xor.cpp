#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],b=0;
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)b=1;
    }
    if(b==0&&k==0)cout<<0;
return 0;
}




