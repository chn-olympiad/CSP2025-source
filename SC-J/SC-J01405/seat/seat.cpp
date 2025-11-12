#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],s[105];
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
        s[i]=a[i];
    }
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(s[i]==a[1])
        {
            int x=(i+n-1)/n;
            if(x%2==1)
            {
                cout<<x<<" "<<(i+n-1)%n+1;
            }
            else{
                cout<<x<<" "<<n-(i+n-1)%n;
            }
        }
    }
    return 0;
}
