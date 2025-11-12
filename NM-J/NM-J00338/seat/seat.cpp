#include<bits/stdc++.h>
using namespace std;
int n,m,a[134],kaochangmap[134][421],k;
bool cmp(int a,int b)
{
    return a>b;
}
bool sir=false;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i];
        }
    }
    int mubiao=a[0];
    sort(a+1,a+1+n,cmp);
    for(int i=1; i<=n; i++)
    {
        for(int j=m; j>0; j--)
        {
            if(a[k]==mubiao)
            {
                cout<<i<<" "<<j;
                return 0;
            }
            kaochangmap[i][j]=a[k];
            k++;
        }
        for(int j=0; j<m; j++)
        {
            if(a[k]==mubiao)
            {
                cout<<i<<" "<<j;
                return 0;
            }
            kaochangmap[i][j]=a[k];
            k++;
        }
    }
    return 0;
}
