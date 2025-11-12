#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,a1=0,cnt=1;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>x;
        if(i==0)
        {
            a1+=x;
        }
        else
        {
            if(x>a1)
            {
                cnt++;
            }
        }
    }
    if(cnt<=n)
    {
        cout<<"1"<<" "<<cnt;
    }
    else
    {
        if(n+1<=cnt<=2*n)
        {
            cout<<"2"<<" "<<n-(cnt-n)+1;
        }
    }
    return 0;
}
