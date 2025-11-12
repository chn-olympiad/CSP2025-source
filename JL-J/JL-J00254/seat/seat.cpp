#include<bits/stdc++.h>
using namespace std;
int n,m;
int num;
int im[110];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++)
    {
        cin>>im[i];
    }
    int r=im[1];
    sort(im+1,im+1+n*m,cmp);
    int num;
    for(int i=1;i<=x;i++)
    {
        if(im[i]==r)
        {
            num=i;
        }
    }
    int l,h;
    if(num%n!=0)
    {
        l=num/n+1;
    }else
    {
        l=num/n;
    }
    if(l%2==1)
    {
        h=num%n;
    }else
    {
        h=n-num%n+1;
    }
    if(h==0)
    {
        h=n;
    }
    cout<<l<<' '<<h;
    return 0;
}
