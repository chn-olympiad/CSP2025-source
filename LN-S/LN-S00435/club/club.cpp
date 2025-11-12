#include <bits/stdc++.h>
using namespace std;
int m;
int a[60000],b[60000],c[60000];
bool d[10000];
int e[100];
int sum;
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int p=1;
        int f=0;
        sum=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            d[i]=0;
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]!=0||c[i]!=0)
            {
                f=1;
            }
        }

        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        sort(c+1,c+1+n,cmp);
        e[1]=0;
        e[2]=0;
        e[3]=0;
         if(f==0)
        {
            for(int i=1;i<=n/2;i++)
            {
                sum+=b[i];
            }
            cout<<sum<<endl;
            continue;
        }
        for(int j=1;j<=n;j++)
        {

            if(d[j]==0)
            {
                int t=max(max(a[j],b[j]),c[j]);
                if(t==a[j])
                {
                    if(e[1]<n/2)
                    {
                        sum+=a[j];
                        e[1]++;
                        d[j]=1;
                        p=0;
                    }
                    else if(e[1]>=n/2&&d[j+1]==0&&p==1)
                    {
                       sum+=max(max(a[j],a[j+1]+b[j]),a[j]+b[j+1]);
                       d[j+1]=1;
                    }
                }
                 if(t==b[j])
                {
                    if(e[2]<n/2)
                    {
                        sum+=b[j];
                        e[2]++;
                        d[j]=1;
                    }
                }
                 if(t==c[j])
                {
                    if(e[3]<n/2)
                    {
                        sum+=c[j];
                        e[3]++;
                        d[j]=1;
                    }
                }

            }
        }
        cout<<sum;
        cout<<endl;

    }
     return 0;
}
