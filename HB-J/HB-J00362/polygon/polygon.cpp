#include <bits/stdc++.h>

using namespace std;

int a[5005];
int n;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int i,j,k;
    int maxnum=-1;
    int sum=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]>maxnum)
        {
            maxnum=a[i];
        }
    }
    if(sum>2*maxnum)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}
