#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin>>n;
    int arhh[n+1]={0};
    int max0=0;
    int sum=0;
    int count0=0;
    for (int i=1;i<=n;i++)
    {
        cin>>arhh[i];
        max0=max(max0,arhh[i]);
        sum+=arhh[i];
    }
    if (sum>2*max0)
    {
        count0++;
    }
    cout<<count0;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
