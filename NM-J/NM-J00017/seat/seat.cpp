#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],l,p;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==R)
        {
            l=i/n+1;
            p=i%n;
            if(p==0)
            {
                l--;
                p=n;
            }
            if(l%2==0)
            {
                p=n-p+1;
            }
        }
    }
    cout<<l<<" "<<p<<endl;
    return 0;
}
