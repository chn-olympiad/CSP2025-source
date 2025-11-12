include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in",stdin);
    freopen("seat.out",stdout);
    int n,a,s=0,q=0,i=0,p[100],c[100];
    cin>>n>>a;
    if (n==1&&a==1)
    {
        cout<<"1"<<"1";
    }
    for (int i=0;i<n*a;i++)
    {
        cin>>p[i];
    }
    for(int i=1;i<=n*a;i++)
    {
        if (p[i]<p[i-1])
        {
            c[i-1]=p[i-1];
        }
        else
        {
            c[i-1]=p[i];
        }
    }
    for (int i=0;i<n*a;i++)
    {
        for (int j=0;j<=n*a;j++)
        {
            if (p[i]==s[j])
            {
                s=c[j];
            }
        }
    }
    q=s/n;
    if (q%2==0)
    {
        i=s%n;
    }
    else
    {
        i=n-s%n;
    }
    cout<<q<<i;
    return 0;
}
