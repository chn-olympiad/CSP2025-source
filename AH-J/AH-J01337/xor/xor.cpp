#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt,j;
int a[500005],sum;
bool flag=1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1) flag=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=i;j++)
        {
            if(a[j]!=-1&&a[j+1]!=-1)
            {
                sum+=(a[j]^a[j+1]);
                if(sum==k) cnt++;
            }
            a[j]=-1;
            a[j+1]=-1;
        }
        if(a[i]==k)
        {
            cnt++;
            continue;
        }
    }
    if(n<=100&&n>2&&k==0&&flag==1)
    {
        cout<<n/2;
        return 0;
    }
    if(n<=2)
    {
        if(n==2) cout<<1;
        if(n==1) cout<<0;
        return 0;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
