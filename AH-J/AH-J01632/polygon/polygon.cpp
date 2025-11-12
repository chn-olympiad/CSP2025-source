#include<bits/stdc++.h>
using namespace std;
int a[5555];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int i,j,k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    int s=0;
    for(i=3;i<=n;i++)
    {
        for(j=1;j<=i-2;j++)
        {
            if(s>=998244353)
                s%=998244353;
            int max1=-1,s1=0,ss=0;
            for(k=j;k<=i;k++)
            {
                ss++;
                s1+=a[k];
                max1=max(max1,a[k]);
            }
            if(ss<3)
                continue;
            if(s1<=(max1*2))
                continue;
            s++;
        }
    }
    cout<<s<<endl;
    return 0;
}
