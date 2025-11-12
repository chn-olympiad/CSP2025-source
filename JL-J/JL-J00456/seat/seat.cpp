#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        s=a[1];
    }
    sort(a+1,a+n*m+1,cmp);
    freopen("seat.out","w",stdout);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            cout<<(i-1)/n+1<<" ";
            if(((i-1)/n)%2==0) cout<<i-(i-1)/n*n;
            else cout<<m-(i-(i-1)/n*n)+1;
        }
    }
    return 0;
}
