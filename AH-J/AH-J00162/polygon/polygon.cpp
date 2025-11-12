#include<iostream>
using namespace std;
int mian()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,max=0,count=0;
    char a[500000]={};
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>a[i];
    }
    for(int j=0;j<n;j++)
    {
        for(int k=j;k<n;k++)
        {
            for(int b=k;b<n;b++)
            {
                if(a[j]>=a[k]>=a[b]||a[j]>=a[b]>=a[k])
                {
                    max=a[j]*2;
                }
                else if(a[k]>=a[j]>=a[b]||a[k]>=a[b]>=a[j])
                {
                    max=a[k]*2;
                }
                else if(a[b]>=a[j]>=a[k]||a[b]>=a[k]>=a[j])
                {
                    max=a[b]*2;
                }
                if(a[j]+a[k]+a[b]>max)
                {
                  count++;
                }
            }
        }
    }
    cout <<count;
    return 0;
}
