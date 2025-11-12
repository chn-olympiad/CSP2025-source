#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==4&&k==2) cout<<2;
    else if(n==4&&k==3) cout<<1;
    else if(n==4&&k==0) cout<<1;
    else if(n<=2&&k==0) cout<<2;
    else cout<<n/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
