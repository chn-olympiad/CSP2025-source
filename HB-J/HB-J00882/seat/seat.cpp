#include<bits/stdc++.h>
using namespace std;
int s[12][12],r,c,i;
int m,n;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(c=1;c<=n;c++)
        for(r=1;r<=m;r++)
            cin>>s[r][c];
    int x=s[1][1];
    for(c=1;c<=n;c++)
    {
        for(r=1;r<=m;r++)
        {
            for(i=r+1;i<=m;i++)
                if(s[c][r]<=s[c][i])
                    swap(s[c][r],s[c][i]);
        }
    }
    for(r=1;r<=m;r++)
    {
        if(r%2==1)
        {
            for(c=1;c<=n;c++)
            {
                for(i=c+1;i<=n;i++)
                    if(s[c][r]<=s[i][r])
                        swap(s[c][r],s[i][r]);
            }
        }
        else
        {
            for(c=1;c<=n;c++)
            {
                for(i=c+1;i<=n;i++)
                    if(s[c][r]>=s[i][r])
                        swap(s[c][r],s[i][r]);
            }
        }

    }
   for(c=1;c<=n;c++)
   {
       for(r=1;r<=m;r++)
            if(s[c][r]==x) cout<<r<<" "<<c;
   }
    return 0;
}
