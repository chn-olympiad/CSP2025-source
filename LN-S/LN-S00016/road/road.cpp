#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a[10],n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<=a[j+1])
            {
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }

        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
