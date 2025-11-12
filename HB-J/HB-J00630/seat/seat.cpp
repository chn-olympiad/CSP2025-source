#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,m,r;
int a[N];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            int x,m;
            x=(i-1)/n+1;
            m=i-(x-1)*n;
            if(x%2==1) cout<<x<<' '<<m;
            else cout<<x<<' '<<n-m+1;

            return 0;
        }
    }

    return 0;
}

