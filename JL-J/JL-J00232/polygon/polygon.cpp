#include<bits/stdc++.h>
using namespace std;
int a[6000],b[6000][6000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m;
    cin>>n;
    if(n<2)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                m=a[j];
                a[j]=a[j+1];
                a[j+1]=m;
            }
        }
    }
    fclose[stdin];
    fclose[stdout];
    return 0;
}
