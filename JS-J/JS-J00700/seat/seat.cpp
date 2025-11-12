#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a1,a;
    int seat=1;
    cin>>a1;
    for(int i=1;i<n*m;i++)
    {
        cin>>a;
        if(a>a1)
        {
            seat++;
        }
    }
    int nn,mm;
    mm=seat/n;
    if(seat%n!=0)   mm++;
    if(mm%2==0)
    {
        if(seat%n==0)
        {
            nn=1;
        }
        else
        {
            nn=n-(seat%n)+1;
        }

    }
    else
    {
        if(seat%n==0)
        {
            nn=n;
        }
        else
        {
            nn=seat%n;
        }
    }
    cout<<mm<<" "<<nn<<endl;
    return 0;
}

