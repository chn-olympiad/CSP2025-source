#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{

    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int seats;
    cin>>n>>m;
    seats=m*n;
    int a[1000]={};
    for(int i=1;i<=seats;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    int rs=0;
    sort(a+1,a+seats+1,cmp);
    for(int i=1;i<=seats;i++)
    {

        if(a[i]==r)
        {
            rs=i;
        }
    }

    int x=0;
    int y=0;
    bool yflag=0;
    if((rs%n)>0)
    {
        yflag=1;
    }
    if(yflag)
    {
        y=(rs/n) + 1;
    }
    else{
        y=rs/n;
    }

    int ans=rs%n;
    if(ans==0)
        ans=n;
    if(y%2==1)
    {
        x=ans;
    }
    else
    {

        x=n-((ans)-1);
    }

    cout<<y<<" "<<x;
    return 0;
}
