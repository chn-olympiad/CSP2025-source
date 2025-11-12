#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[121];
int f(int a, int b)
{
    return a>b;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,o=0,s=0;
    cin>>n>>m;
    cin>>s;
    b[1]=s;
    for(int i=2;i<=n*m; i++)
        cin>>b[i];
    sort(b+1,b+(n*m)+1,f);
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
        {

            for(int j=1; j<=m; j++)
            {
                o++;
                if(b[o]==s)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }

            }
        }
        if(i%2==0)
        {

            for(int j=m; j>=1; j--)
            {
                o++;
                if(b[o]==s)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }

            }
        }
    }
    return 0;
}
