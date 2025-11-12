#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[100010];
    int n,m;
    int nn,mm;
    double nnn;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int t=a[1];
    sort(a+1,a+n*m+1);
    int a2[100010];
    for(int i=1;i<=n*m;i++)
    {
        int j=n*m;
        a2[i]=a[j-i+1];
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a2[i]==t)
        {
            nnn=ceil(i*1.0/n);
            nn=nnn;
            if(nn%2==1)
            {
                if(i%n==0)
                {
                  mm=n;
                  break;
                }
                mm=i%n;

            }
            if(nn%2==0)
            {
                if(i%n==0)
                {
                    mm=1;
                    break;
                }
                mm=n-i%n+1;

            }
            break;
        }

    }
    cout<<nn<<" "<<mm;
    return 0;
}
