#include <bits/stdc++.h>
using namespace std;
int n,k,sum,a[500005],s[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],s[i]=s[i-1]^a[i];
    if(k==0)
    {
        cout<<n/2;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            int num=s[j]^s[i-1];
            if(num==k)
            {
                i=j;
                //printf("%d %d %d %d %d\n",i-1,j,s[i-1],s[j],num);
                sum++;
                break;
            }
        }
    cout<<sum;
    return 0;
}
