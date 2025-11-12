#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[112],r;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++)
    {
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+1+n*m,cmp);
    int pos;
    for(int i=1; i<=n*m; i++)
    {
        if(a[i]==r)
        {
            pos=i;
            break;
        }
    }
    int k=(pos-1)/n;
    int b=pos-k*n;
    if(k%2==0)
    {
        cout<<k+1<<" "<<b;
    }
    else
    {
        cout<<k+1<<" "<<n-b+1;
    }
    return 0;
}
