#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int w=a[1];
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=m*n;i++)
    {
        if(w==a[i])
        {
            w=i;
            break;
        }
    }
    int k;
    if(w%m==0)
    {
        cout<<w/m<<" ";
        k=w/m;
    }
    else
    {
        cout<<w/m+1<<" ";
        k=w/m+1;
    }
    if(k%2==0)
    {
        if(w%m==0)
        {
            cout<<1;
        }
        else
        {
            cout<<m-((w%m)-1);
        }
    }
    else
    {
        if(w%m==0)
        {
            cout<<m;
        }
        else
        {
            cout<<w%m;
        }
    }
    return 0;
}
