#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int cnt=0,d=0;
        for(int j=0;j<=i;j++)
        {
            if(a[j]>d)
            {
                d=a[j];
            }
        }
        for(int j=i;j>=0;j--)
        {
            cnt+=a[j];
            if(cnt>d*2)
            {
                sum++;
                //cout<<cnt<<" "<<d<<endl;
            }
        }
    }
    cout<<sum;
    return 0;
}
