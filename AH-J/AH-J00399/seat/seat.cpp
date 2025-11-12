#include<bits/stdc++.h>
using namespace std;
int a[225],n,m;
int main(void)
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int t=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            if(i%(2*n)<=n)
            {
                if(i%n==0)
                {
                    cout<<i/n<<" "<<n;
                    break;
                }
                else
                {
                    cout<<i/n+1<<" "<<i%n;
                }
            }
            else
            {
                if(i%n==0)
                {
                    cout<<i/n<<" "<<1;
                    break;
                }
                else
                {
                    cout<<i/n+1<<" "<<n-i%n+1;
                    break;
                }
            }
        }
    }
    return 0;
}
