#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5005],ans;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int l=1;l<=n-2;l++)
    {
        for(int r=l+2;r<=n;r++)
        {
            int sum=0,maxn=-1e9;
            for(int i=l;i<=r;i++)
            {
                sum+=a[i];
                maxn=max(maxn,a[i]);
            }
            if(sum>maxn*2)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
