#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int s,ans=0;
    cin>>s;
    int a[s];
    for(int i=1;i<=s;i++)
        cin>>a[i];
    for(int f=1;f<=s;f++)
    {
        for(int o=f+1;o<=s;o++)
        {
            for(int p=o+1;p<=s;p++)
            {
                if(a[f]>a[o] || a[f]>a[p] || a[f]<a[o]+a[p])
                {
                    ans++;
                }
                if(a[o]>a[f] || a[o]>a[p] || a[o]<a[f]+a[p])
                {
                    ans++;
                }
                if(a[p]>a[o] || a[p]>a[f] || a[p]<a[o]+a[f])
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
