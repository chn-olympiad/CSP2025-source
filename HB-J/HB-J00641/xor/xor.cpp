#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    int flag=1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==m)
        {
            flag=1;
            sum++;
            continue;
        }
        if(flag==1)
        {
            cnt=a[i];
            flag=0;
            if(cnt==m)
            {
                flag=1;
                sum++;
                continue;
            }
        }
        else
        {
            cnt^=a[i];
            if(cnt==m)
            {
                flag=1;
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
