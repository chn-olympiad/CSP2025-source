#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a,ma=1,q;

int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    const char endl='\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    //------------
    cin>>n>>m>>a;
    for (int k=1;k<n*m;k++)
    {
        cin>>q;
        if(q>a)
        {
            ma++;
        }
    }
    ll am=ma%(2*n);
    if(am<=n&&am!=0)
    {
        cout<<ma/(2*n)*2+1<<" "<<am;
    }
    else if(am!=0)
    {
        cout<<ma/(2*n)*2+2<<" "<<2*n-am+1;
    }
    else
    {
        cout<<ma/(2*n)*2<<" "<<1;
    }
    return 0;
}
