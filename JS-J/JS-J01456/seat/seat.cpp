#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[15][15]={0},b[105];
    int n,m;
    cin>>n>>m;
    int nm=n*m;
    for(int i=1;i<=nm;i++)
    {
        cin>>b[i];
    }
    int xr=b[1],cnt=1;
    sort(b+1,b+nm+1,greater<int>());
    for(int i=1;i<=m;i++)
    {
        if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                if(b[cnt]==xr)
                    cout<<i<<" "<<j<<endl;
                a[j][i]=b[cnt++];
            }
        }
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[cnt]==xr)
                    cout<<i<<" "<<j<<endl;
                a[j][i]=b[cnt++];
            }
        }
    }
    return 0;
}
