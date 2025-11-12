#include <iostream>
#include <cstdlib>
int a[102]={0};
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,mn,i,j,t,a1,r,c;
    cin>>n>>m;
    mn=m*n;
    for(i=1;i<=mn;i++)
        cin>>a[i];
    a1=a[1];
    for(i=1;i<=mn-1;i++)
        for(j=1;j<=mn-i;j++)
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    for(i=1;i<=mn;i++)
        if(a[i]==a1)
            break;
    c=2*(i/(2*n));
    if(i%(2*n)==0)
        r=1;
    else if(i%(2*n)>=1&&i%(2*n)<=n)
    {
        r=i%(2*n);
        c++;
    }
    else
    {
        r=(2*n)-(i%(2*n))+1;
        c+=2;
    }
    cout<<c<<' '<<r<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
