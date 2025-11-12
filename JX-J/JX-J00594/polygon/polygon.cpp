//xjz0918 CSP-J2025RP++
//From GAN NAN SHI DA FU ZHONG
#include<iostream>
#include<cmath>
using namespace std;
long long n,a[5010],ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=3)
    {
        if(n==1||n==2)
        {
            cout<<0;
            return 0;
        }
        if(n==3)
        {
            if((a[1]+a[2])>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
            {
                cout<<1;
                return 0;
            }
        }
        cout<<0;
        return 0;
    }

    return 0;
}
