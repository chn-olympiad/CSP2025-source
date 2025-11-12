#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a[10005],num,m,sum=0;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==m)
        {
            sum++;
        }
    }
    for (int i=1;i<n;i++)
    {
        for (int j=2;j<=n-i+1;j++)
        {
            num=a[i];
            cout<<" "<<a[i]<<endl;
            for (int f=j;f<j+i;f++)
            {
                num=(num^a[f]);
                cout<<" "<<a[f]<<endl;
            }
            if (num==m)
            {
                sum++;
            }
            cout<<endl;
        }
    }
    cout<<sum;
    return 0;
}
