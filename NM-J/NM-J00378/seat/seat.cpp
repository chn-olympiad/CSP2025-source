#include <iostream>
#include <cstring>
#include <cstdio>
#define lli long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    lli n,m;
    cin>>m>>n;
    lli me,ot,nu=0;
    cin>>me;
    for(int i=2;i<=n*m;i++)
    {
        cin>>ot;
        if(ot>me)
        {
            nu++;
        }
    }
    lli c,r;
    nu++;
    c=nu/m+1;
    if(nu%m==0)c--;
    r=nu%m;
    if(r==0)r=n;
    if(c%2==0)r=n-r;
    cout<<r<<" "<<c<<endl;
    return 0;
}
