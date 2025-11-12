#include <bits/stdc++.h>
using namespace std;
long long n,m,s,d,f,t,a[100000];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(s=0;s<n;s++)
    {
        cin>>a[s];
    }
    sort(a,a+n,cmp);
    for(s=t=0;s<n-2;s++)
    {
        for(d=s+2;d<n;d++)
        {
            for(m=s,f=0;m<=d;m++)
            {
                f=f+a[m];
            }
            if(f>a[s]*2)
             t++;
        }
    }
    cout<<t%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
