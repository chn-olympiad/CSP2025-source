#include <bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
bool cmp(int x,int y)
{
    return x>y;
}
bool cmp1(int q,int w)
{
    return q>w;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1&&m==1)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    else if(m==1){
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int l=a[1];
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==l)
            {
                cout<<i<<" "<<1<<" ";
            }
        }
        return 0;
    }
    else if(n==1)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>b[j];
        }
        int r=b[1];
        sort(b+1,b+m+1,cmp1);
        for(int j=1;j<=m;j++)
        {
            cout<<b[j]<<" ";
            if(b[j]==r)
            {
                cout<<1<<" "<<j<<" ";
            }
        }
        return 0;
    }


}
