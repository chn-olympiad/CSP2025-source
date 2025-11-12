#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("seat.in","r","stdin");
    //freopen("seat.out","w","stdout");
    int n,m,a[9178],num=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int k=a[1];
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]<a[i+1])
        {
            int t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }

    }
    int q=1;
    for(int i=1;i<=n*m;i++)
    {
        if(k==a[i])
        {
            while(m>=i)
            {
                q=i;
                i-=m;
                num++;
            }
        }
    }

    cout<<num<< " " <<q;
    return 0;
}
