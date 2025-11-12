#include<bits/stdc++.h>
using namespace std;
int cj[100];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    int a,b,xr;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++)
    {
        cin>>cj[i];
    }
    xr=cj[1];
    sort(cj+1,cj+a*b+1);
    for(int i=a*b;i>=1;i--)
    {
        if(cj[i]==xr)
            xr=a*b-i;
    }
    xr++;
    int x=xr%b,y=xr/b+1;//
    if(y%2==0)
    {
        cout<<y<<' '<<a-x+1;
    }
    else
    {
        if(x==0)
            cout<<y<<' '<<a;
        else
            cout<<y<<' '<<x;
    }
}
