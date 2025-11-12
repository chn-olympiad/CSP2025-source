#include<bits/stdc++.h>
using namespace std;
int n,k,a[11000],c;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int x=n;x>=1;x--)
    {
        for(int i=1;i<=n-x+1;i++)
        {
            c=a[1];
            for(int j=i;j<=x;j++)
                c^=a[i+j];
            if(c==k)
            {
                cout<<x;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
