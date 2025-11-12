#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[505],qzh[505];
int he;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","d",stdout);
    int n;
    cin>>n;
    qzh[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        qzh[i]=qzh[i-1]+a[i];
    }
    int cnt=0;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+2;j<=n;j++)
        {
            he=qzh[j]-qzh[i-1];
            if(he>2*a[j])
            {
                cnt++;
            }
            if(j-i+1>3)
            {
                for(int p=i+1;p<=j-1;p++)
                {
                    for(int q=p;q<=j-1;q++)
                    {
                        if((he-qzh[q]+qzh[p-1]>2*a[j])&&(j-i+1-(q-p+1)>=3))
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout <<cnt%998244353;
    return 0;
}
