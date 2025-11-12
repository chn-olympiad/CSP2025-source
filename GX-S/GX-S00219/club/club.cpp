#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct m{
    int a,b,c;
}m[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int A,B,C,y=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>m[i].a>>m[i].b>>m[i].c;
        }
        for(int i=1;i<=n;i++)
        {
            if(m[i].a>m[i].b&&m[i].a>m[i].b&&A<=(n/2))
            {
                y+=m[i].a;
                A++;
            }
            else if(m[i].b>m[i].a&&m[i].b>m[i].c&&B<=(n/2))
            {
                y+=m[i].a;
                B++;
            }
            else if(m[i].c>m[i].a&&m[i].c>m[i].b&&C<=(n/2))
            {
                y+=m[i].a;
                C++;
            }
        }
        cout<<y<<endl;
    }
    return 0;
}
