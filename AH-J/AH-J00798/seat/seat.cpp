#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,c=0,hang,lie;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        b=a[1];
    }
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==b)
        {
            c++;
            break;
        }
        else c++;
    }
    if(c%n==0)
    {
        lie=c/m;
        hang=m;
    }
    else
    {
        lie=c/n+1;
        if((c/n+1)%2==0)hang=n+1-c/n;
        else hang=n-c/n;
    }
    cout<<lie<<" "<<hang;
    return 0;
}
