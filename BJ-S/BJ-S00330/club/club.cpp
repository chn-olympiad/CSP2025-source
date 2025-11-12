#include<bits/stdc++.h>
using namespace std;
int T,n,f[100010],t[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        int d1,d2,d3;
        int flg=0;
        t[1]=0;
        t[2]=0;
        t[3]=0;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            cin>>d1>>d2>>d3;
            if(t[1]<n/2&&f[i-1]+d1>f[i])
            {
                f[i]=f[i-1]+d1;
                flg=1;
            }
            if(t[2]<n/2&&f[i-1]+d2>f[i])
            {
                f[i]=f[i-1]+d2;
                flg=2;
            }
            if(t[3]<n/2&&f[i-1]+d3>f[i])
            {
                f[i]=f[i-1]+d3;
                flg=3;
            }
        }
        cout<<f[n]<<endl;
    }
    return 0;
}
