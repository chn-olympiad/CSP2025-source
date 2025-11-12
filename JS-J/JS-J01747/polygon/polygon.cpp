#include<iostream>
#include<algorithm>
using namespace std;
int a[6000],n,j,ansx;
void tp(int dep,int ans,int num,int zh)
{
    for(j=dep+1;j<=n;j++)
    {
        if((zh>=a[j])||(num<=3))
        {
            for(int i=j;i<=n;i++)
            {
                tp(i,ans+1,num+1,zh+a[i]);
            }
            return;
        }
    }
    if(num>=3)
        ansx=max(ansx,ans);
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        tp(i,0,1,a[i]);
    }
    cout<<ansx-2;
    return 0;
}
