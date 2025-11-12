#include <bits/stdc++.h>
using namespace std;
long long n,m,c,r,a,seat;
long long luvia;
long long score[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>score[i];
    }
    a=score[1];
    sort(score,score+n*m+1);
    for(long long i=1;i<=n*m;i++)
    {
        if(score[i]==a)
        {
            seat=n*m-i+1;
            break;
        }
    }
    r=seat/m;
    if(seat%m!=0)
    {
        r++;
        if(r%2==1)
        {
            c=seat-(r-1)*m;
        }
        else
        {
            c=(m+1)-(seat-(r-1)*m);
        }
    }
    else
    {
        if(r%2==1)
        {
            c=m;
        }
        else
        {
            c=1;
        }
    }
    cout<<r<<" "<<c;
    return 0;
}
