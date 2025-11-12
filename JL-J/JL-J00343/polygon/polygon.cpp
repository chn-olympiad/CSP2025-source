#include <bits/stdc++.h>
using namespace std;
int n,num;
int a[5100],f[5100];
bool check(int x,int y)
{
    int maxv=-1,cnt=f[y]-f[x-1];
    for(int i=x;i<=y;i++)
        maxv=max(maxv,a[i]);
    maxv*=2;
    return cnt>maxv;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+2;j<=n;j++)
        {
            if(check(i,j))
            {
                //cout<<i<<" "<<j<<" "<<num<<endl;
                num++;
                num%=998;
                num%=244;
                num%=353;
            }

        }
    }
    cout<<num;
    return 0;
}
