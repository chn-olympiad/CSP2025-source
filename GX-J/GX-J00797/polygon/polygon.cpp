#include<bits/stdc++.h>
using namespace std;
const int M=30000000;
int a[M];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,num=0,t=0,MAX=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i;j<=n;j++)
        {

            t=a[j]+a[j+1]+a[j+2];
            MAX=a[j];
            if(MAX<a[j+1])
            {
                MAX=a[j+1];
            }
            if(MAX<a[j+2])
            {
                MAX=a[j+2];
            }
            MAX*=2;
            if(MAX>=t)
            {
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}
