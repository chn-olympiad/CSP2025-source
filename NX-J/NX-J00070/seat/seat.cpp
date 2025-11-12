#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
bool cmp(int x,int y)
{
    return x>y;
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
    int q=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==q)
        {
            cout<<i%n<<i%m;
            return 0;
        }
    }
    return 0;
}

