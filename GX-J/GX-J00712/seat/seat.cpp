#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[150]= {0},s[12][12]= {0},n,m,r,f=1,j=0;
    cin>>n>>m;
    int nm=n*m;
    cin>>r;
    a[1]=r;
    for(int i=2; i<=nm; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=nm; i++)
    {
        for(int o=1; o<=nm; o++)
        {
            if(a[o]<a[o+1])
            {
                j=a[o];
                a[o]=a[o+1];
                a[o+1]=j;

            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int o=1; o<=m; o++)
        {
            s[i][o]=a[f];
            f++;
            cout<<s[i][o]<<" ";
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int o=1; o<=m; o++)
        {
            if(s[i][o]==r)
                cout<<i<<" "<<o;

        }
    }
    return 0;
}
