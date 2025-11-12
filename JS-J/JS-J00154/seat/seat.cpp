#include<bits/stdc++.h>
using namespace std;
int num[110];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>num[i];
    }
    int f=num[1];
    sort(num+1,num+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(num[i]==f)
        {
            f=i;
        }
    }
    int c=0;
    while(f>n)
    {
        c++;
        f-=n;
    }
    c++;
    int r=0;
    if(c%2==0)
    {
        r=f%n;
        r=n-r+1;
    }
    if(c%2==1)
    {

       if(f%n==0)
       {
           r+=n;
       }
       else
       {
           r+=f%n;
       }
    }
    cout<<c<<" "<<r;
    return 0;
}
