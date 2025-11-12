#include <bits/stdc++.h>
using namespace std;
int n,a[100000],p=2,m,d[10000],k;
bool v(int a,int b)
{
    return a<b;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,v);
    while(p<=n)
    {
        for(int j=0;j<n;j++)
        {
            k=0;
            int b=0;
            for(int i=p+j;i>=0;i--)
            {
                b+=a[i];
            }
            for(int i=0;i<j;i++)
            {
                if(d[i]==b)
                {
                    k=1;
                }
            }
            if(k==1)
            {
                break;
            }
            d[j]=b;
            if(b>a[p]*2)
            {
                m++;
            }
        }
        p++;
    }
    cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
