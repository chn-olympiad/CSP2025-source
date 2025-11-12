#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,q,s,ias,dick=0;
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    for(int j=0;j<=n;j++)
    {
        if(a[j]>a[j+1])
        {
            q=a[j+1];
            a[j+1]=a[j];
            a[j]=q;
        }
    }
    for(int x=0;x<=n;x++)
        for(int y=0;y<=n;y++)
        {
            s=max(a[y],a[y+1],a[y+2]);
            ias=a[y]+a[y+x]+a[y+x+1]-s;
            if(s<ias)
                dick++;
        }
        cout<<dick<<endl;
    return 0;
}
