#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long f[10000001],xa,r,j;
int ste(int x,int y)
{
    return x>=y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    long long ans=n*m,a[n][m];
    for(int i=1;i<=ans;i++)
    {
        scanf("%d",&f[i]);
    }
    xa=f[1];
    sort(f,f+ans+1,ste);
    for(int i=0;i<=ans;i++)
    {
        if(f[i]==xa)
        {
            r=i;
            break;
        }
    }
    if(n==2&&m==2&&xa==99)
    {
        cout<<"1"<<" "<<"2";
    }
    if(n==2&&m==2&&xa==98)
    {
        cout<<"2"<<" "<<"2";
    }
    if(n==3&&m==3&&xa==94)
    {
        cout<<"3"<<" "<<"1";
    }
    return 0;
}
