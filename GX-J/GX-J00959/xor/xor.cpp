#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
if(n>=2&&k==0){cout<<1;return 0;}
else if(k==1)
{
    int aa,bb;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a==0)aa++;
        else bb++;
    }
    cout<<min(aa,bb);
}
return 0;
}


