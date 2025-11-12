#include<bits/stdc++.h>
using namespace std;
long long sum;
int a[5001],f[5001],m[5001],n;
long long summ(int dou)
{
    long long summm=0;
    for(int k=1;k<=dou;k++)
    {
        summm+=a[k];
    }
    return summm;
}
long long bag(int aa)
{
    int ans=1;
    int w=f[aa-1];
    if(w<=a[aa]) return 0;
    else
    {
        int j=1;
        while(j<aa)
        {
            for(int p=1;p<=j;p++)
            {
                if(w-a[p]>a[aa]) sum++;
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        m[i]=summ(i);
    }
    for(int i=n;i>=3;i--)
    {
        sum+=bag(i);
        memset(f,0,sizeof(f));
    }
    cout << sum%998%353%244;
    return 0;
}
