#include<bits/stdc++.h>
using namespace std;
struct st{
    int nu;
    int cj;
};
st a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    x=n*m;
    for(int i=1;i<=x;i++)
    {
        cin>>a[i].cj;
        a[i].nu=i;
    }
    for(int i=0;i<x;i++)
    {
        for(int j=2;j<=x-i;j++)
        {
            if(a[j].cj>=a[j-1].cj)swap(a[j],a[j-1]);
        }
    }
    int num=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            num++;
            if(a[num].nu==1){
                cout<<i<<' '<<j;
                return 0;
            }

        }
        i++;
        for(int j=m;j>=1;j--)
        {
            num++;
            if(a[num].nu==1){
                cout<<i<<' '<<j;
                return 0;
            }

        }
    }
    return 0;
}
