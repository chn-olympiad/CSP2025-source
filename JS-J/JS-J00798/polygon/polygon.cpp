#include<bits/stdc++.h>
using namespace std;int n; int a[5001];
int he;
unsigned long long s=0;
 int maxz;
void sou(int ceng,int p)
{
    if(ceng==1)
    {
        for(int k=1;k<=p-1;k++)
            {
                if(a[k]+he>maxz)
                {
                    s+=(p-k)%998244353;
                    //return p-k;
                    return;
                }
            }
    }
    else{
        for(int j=p-1;j>=ceng;j--)
        {
            he+=a[j];
            sou(ceng-1,j);
            he-=a[j];
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    if(a[n]==1)
    {
        int sum01=0,sum02=0;
        for(int i=1;i<=n-2;i++)
        {
            sum01+=i;
            sum02+=sum01;

        }
        cout<<sum01+sum02;
        return 0;
    }

    for(int i=n;i>=3;i--)
    {
        for(int j=n;j>=i;j--)
        {
            maxz=2*a[j];
            he=a[j];
            sou(i-1,j);
        }

    }

    cout<<s;
    return 0;
}
