#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,cnt,k,x,y,d;
int a[N];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        if(i==1) cnt=a[i];
    }
    sort(a+1,a+k+1,cmp);
    d=1,x=1,y=1;
    for(int i=1;i<=k;i++)
    {
        if(a[i]==cnt)
        {
            cout<<y<<" "<<x;
            break;
        }
        if(x==n&&d==1) d=-1,y+=1;
        else if(x==1&&d==-1) d=1,y+=1;
        else x+=d;
    }
    return 0;
}
