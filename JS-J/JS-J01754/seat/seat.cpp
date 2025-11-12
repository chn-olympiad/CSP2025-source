#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long n,m;
long long a[105];
long long t;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            int x=(i+m-1)/m,y=(i-1)%n+1;
            cout<<x<<' ';
            if(x%2)
            {
                cout<<y<<endl;
            }
            else
            {
                cout<<n-y+1<<endl;
            }
            return 0;
        }
    }
    return 0;
}
