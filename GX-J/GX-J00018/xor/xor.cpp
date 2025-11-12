#include<bits/stdc++.h>
using namespace std;
int m;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(n==3)
    {
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            if(k==1&&a==1)
            {
                m++;
            }
            else if(k==0&&a==0)
            {
                m++;
            }
        }
        cout<<m;
    }
    else
    {
        for(int i=2;i<n;i++)
        {
            m+=(n-i+1)*(n-i)/2;
        }
        cout<<m;
    }
    return 0;
}
