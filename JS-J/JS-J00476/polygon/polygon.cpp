#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[5005];
int n;
bool cmp(int x,int y)
{
    return x>y;
}
int f(int,int,int);

int main()
{
    int cnt=0;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int b=3;b<=n;b++)
    {
        for(int x=1;x<=n-b+1;x++)
        {
            cnt+=f(b-1,x+1,a[x]);
        }
    }
    cout<<cnt%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

int f(int nd,int id,int mnum)
{
    if(nd==1)
    {
        for(int i=id+1;i<=n;i++)
        {
            if(mnum<a[i])
                return 1;
        }
    }
    for(int j=id;j<=n-id+1;j++)
    {
        return f(nd-1,j+1,mnum-a[j]);
    }
    return 0;
}







