#include<bits/stdc++.h>
using namespace std;
int n,a[10000],k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1)
    {
        if(a[0]==k) cout<<1;
        if(a[0]!=k) cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
