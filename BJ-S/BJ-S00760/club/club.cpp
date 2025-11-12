#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,a[100005][4],d[1005][1005],p[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int i,j;
    cin>>t;
    while(t--)
    {
        memset(d,0,sizeof(d));
        int as=0,cnt=0,s=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=3;j++)
                cin>>a[i][j];
            p[i]=a[i][1];
            if(a[i][3]==0)cnt++;
            s+=max(a[i][1],max(a[i][2],a[i][3]));
        }
        if(n>1000)
        {
            if(cnt==n)
            {
                sort(p+1,p+n+1);s=0;
                for(i=n/2+1;i<=n;i++)
                    s+=p[i];
                cout<<s<<endl;
            }
            else cout<<s<<endl;
        }
        else
        {
            for(int k=1;k<=n;k++)
            {
                for(i=min(k,n/2);i>=0;i--)
                {
                    for(j=min(n/2,k);j>=0;j--)
                    {
                        if(k-i-j>n/2||k-i-j<0)continue;
                        int p1=0,p2=0,p3=0;
                        if(k-i-j>=1) p1=d[i][j]+a[k][3];
                        if(i>=1) p2=d[i-1][j]+a[k][1];
                        if(j>=1) p3=d[i][j-1]+a[k][2];
                        d[i][j]=max(max(p1,p2),p3);
                        if(k==n)as=max(as,d[i][j]);
                    }
                }
            }
            cout<<as<<endl;
        }
    }
    return 0;
}
