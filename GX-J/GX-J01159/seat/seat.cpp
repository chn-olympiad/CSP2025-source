#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    int len=n*m;
    for(int i=1;i<=len;i++)
    {
        cin>>a[i];
    }
    r=a[1];
    int indx=0;
    sort(a+1,a+1+len,cmp);
    for(int i=1;i<=len;i++)
    {
        if(r==a[i])
        {
            indx=i;
            break;
        }
    }
    int x,y;
    if(indx%n==0)
    {
        x=indx/n;
        y=m;
    }
    else
    {
        cout<<'*';
        x=indx/n+1;
        y=indx%n;
    }
    if(x%2==0)
    {
        y=m-y+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
