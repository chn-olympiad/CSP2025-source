#include<iostream>
using namespace std;
//freopen("seat.in","r","stdin");
//freopen("seat.out","r","stdout");
int main()
{
    int a[105],n,m,s,b,i,c,r,e;
    cin>>n>>m;
    s=0;
    cin>>e;
    for(i=2;i<=n*m;i++)
    {
            cin>>b;
            a[b]=1;
        }
    for(i=100;i>=1;i--)
    {
        if(a[i]==1)
        s++;
        if(i==e)
        {
            c=(s-1)/ n+1;
            if(c%2==0) r=n+1-(s%n);
            else if(c%2==1)
            {
                if(s/n!=0)
                    r=s%n;
                else r=n;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
