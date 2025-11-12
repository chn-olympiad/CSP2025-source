#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,s;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            int x=(i-1)/m+1;
            cout<<x<<" ";
            int y;
            if(x%2==1)
                y=(i-1)%m+1;
            else
                y=m-((i-i)%m+1)+1;
            cout<<y;
            return 0;
        }
    }
    return 0;
}
