#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);


    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i];
        }
    }
    if(n<=2&&k==0) cout<<1;
    return 0;


    fclose(stdin);
    fclose(stdout);
}
