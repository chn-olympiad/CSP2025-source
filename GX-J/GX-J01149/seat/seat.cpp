#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>=b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,cj=0;
    cin>>n>>m;
    long long a[n*m+1];
    for(int i=1;i<=n*m+1;i++)
    {
        cin>>a[i];
    }
    cj=a[1];
    sort(a+1,a+1+n*m,cmp);

    if(n==1)
    {
        for(int i=1;i<=m;i++)
        {
            if(a[i]==cj)
                cout<<1<<" "<<i;
        }
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==cj)
                cout<<i<<" "<<1;
        }
    }
    return 0;
}
