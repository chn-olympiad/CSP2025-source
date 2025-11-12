#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e6+7;
long long a[5050];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long c=0,z=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            c=0;
            for(int k=i;k<=j;k++)
            {
                c+=a[k];
            }
            for(int q=i;q<=j;q++)
            {
                z=max(z,a[q]);
            }
            if(c>2*z&&j-i>=3)
            {

                cnt++;
            }

        }
    }
    cout<<cnt;
    return 0;
}
