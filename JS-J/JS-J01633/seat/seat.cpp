#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int sc;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++) cin>>a[i];
    sc=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int x=1;
    for(int i=1; i<=n*m; i++)
    {
        //cout<<a[i]<<" ";
        if(a[i]==sc)
        {
            x=i;
            break;
        }
    }
    //cout<<x<<'\n';
    if(m==1||x<n) cout<<1<<" "<<x<<'\n';
    else if(n==1) cout<<x<<" "<<1<<'\n';
    else
    {
        bool f=1;//1^ 0v
        int y=0;
        while(x)
        {
            if(x<=n)
            {
                if(f) cout<<y+1<<" "<<x<<'\n';
                else cout<<y+1<<" "<<n-x+1<<'\n';
                break;
            }
            else
            {
                x-=n;
                y++;
                if(f==1) f=0;
                else f=1;
                //cout<<x<<" "<<y<<" "<<f<<'\n';
            }

        }

    }
    return 0;
}
