#include <iostream>
#include <ios>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n,m,q,p=0;//n=hangShu,m=lieShu,q=R's score
    cin>>n>>m;
    int* a=new int[n*m]{0};
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    q=a[0];
    for(int i=0;i<n*m-1;i++)//sort
    {
        for(int j=0;j<n*m-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
    for(int i=0;i<n*m;i++)//search p
    {
        if(q==a[i])
        {
            p=i+1;
            break;
        }
    }
    int p1,p2;
    if(p%n==0)
        p1=p/n;
    else
        p1=p/n+1;
    p2=p-(p1-1)*n;
    if(p1%2==0)
        p2=n-p2+1;
    cout<<p1<<' '<<p2;
    return 0;
}
