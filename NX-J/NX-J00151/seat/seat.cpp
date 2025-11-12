#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long n,m,a[N],cnt=0,c=1,r=1,d,w;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]<a[1]) cnt++;
    }
    cnt=n*m-cnt;
    d=cnt;
    w=cnt;
    while(n*m--)
    {
        if(d>n)
        {

            d-=n;
            c++;
        }
        else
        {
            if(c%2==1)
            {
                r--;
                 if(w%n!=0) r=w%n;
                 else
                 {
                     w/=n;
                     r++;
                 }
            }
            if(c%2==0)
            {

                w=w-w%n;
                r+=w;
            }
        }
    }
    cout<<c<<' '<<r<<endl;
    return 0;
}
