#include<bits/stdc++.h>
using namespace std;
int s1[110],i,j,w,w1=1,a,b,c,d,n,m,x,y,e,t,w3,w2,w4=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    w=n*m;
    for(i=1;i<=w;i++)
        cin>>s1[i];
    a=s1[1];
    while(t==0)
    {
        for(i=1;i<=w;i++)
        {
            if(s1[i]>w2)
            {

                w2=s1[i];
                w3=i;
            }
        }
        if(w2==a)
        {
            b=w4;
            t=-1;
        }
        else
            s1[w3]=0;
        w2=0;
        w3=0;
        w4++;
    }
    c=(b-1)/n+1;
    e=n*2;
    d=b%e;
    if(c==0)
        y=1;
    else
        y=c;
    if(d>n)
    {
        for(i=1;i<=d-n-1;i++)
            w1=w1+2;
        x=d-w1;
        y++;
    }
    if(d<n)
        x=d;
    if(d==0)
    {
        for(i=1;i<=d-n-1;i++)
            w1=w1+2;
        x=d-w1;
        y++;
    }
    cout<<y<<" "<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
