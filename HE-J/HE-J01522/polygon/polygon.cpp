#include<iostream>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin  );
    freopen("polygon.out","w",stdout);
    int n,a[1005];
    cin>>n;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {

        int p=a[i]+a[i+1]+a[i+2];
        if(a[i]<a[i+1])
        {
            int y=a[i];
            a[i+1]=a[i];
            a[i+1]=y;
        }
        if(a[i+2]>a[i])
        {
            int y=a[i];
            a[i]=a[i+2];
            a[i+2]=y;
        }
        if(p>2*a[i])
        {
            num++;
        }


    }
    cout<<num;
    return 0;
}
