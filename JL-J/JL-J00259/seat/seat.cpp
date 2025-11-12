#include <bits/stdc++.h>
using namespace std;
int s[1010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon .out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0; i<n*m; i++)
    {
        cin>>s[i];
    }
    int cnt=s[0];
    sort(s,s+n*m);
    int x=1,y=0,fx=1;
    for (int i=n*m-1; i>=0; i--)
    {
        if (fx==1)
        {
            y++;
        }
        else
        {
            y--;
        }
        if (y==n+1)
        {
            fx=0;
            x++;
            y--;
        }
        if (y==0)
        {
            fx=1;
            x++;
            y++;
        }
        if (s[i]==cnt)
        {
            cout<<x<<" "<<y;
            break;
        }
    }
    return 0;
}
