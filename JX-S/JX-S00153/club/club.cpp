#include <bits/stdc++.h>
using namespace std;
int a1[100000];
int a2[100000];
int a3[100000];
int ans[10];
int main()
{
    freopen("club.in","r",stdin)
    freopen("club.out","w",stdout)
    int t,n,m=0,fl=0,d=0;
    cin >> t;
    for(int z = 1;z<=t;z++){
    cin  >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a1[i] >> a2[i] >>a3[3];
    }

    for(int i = 1;i<=n-1;i++)
            {
        for(int j = 1;j<=n-1;j++)
                {
            if(a1[j]<a1[j+1])
                    {
                swap(a1[j],a1[j+1]);
                swap(a2[j],a2[j+1]);
                swap(a3[j],a3[j+1]);

                    }
                }
            }
           for(int i = 1;i <= n;i++)
    {
        if(a2[i]=0&&a3[i]=0)
{
    for(int i = 1;i <= n/2;i++)
    {
        ans[z]=ans[z]+a[i];
        cout <<ans[z];
    }
}
if(a2[i]=0&&a3[i]=0)
{
    continue;
}
    for(int i = 1;i<=n;i++)
    {
        if(m<=n/2)
        {
        ans[z] = ans[z] + a1[2];
            m++;
        }
        else if(m>n/2)
        {
            for(int i = m;i<=n-1;i++)
            {
        for(int j = m;j<=n-1;j++)
                {
            if(a2[j]<a2[j+1])
                    {
                swap(a2[j],a2[j+1]);
                swap(a3[j],a3[j+1]);

                    }
                }
            }
    ans[z] = ans[z] + a2[i];
    fl++;
        }
    else if(fl <= n/2&&a3[i]>a2[i]&&d<=n/2||fl>n/2)
     {
         ans[z] = ans[z]+ a3[i];
         d++;
     }
    }
}
    }
for(int i=1;i<=t;i++){
cout <<ans[i]<<endl;
}
    return 0;
}
