#include<bits/stdc++.h>
using namespace std;
int t,n,g[100005][3],p[100005],ans;

void c(int l)
{
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<3;j++)
        {
            g[i][j]=0;
        }
    }
}
void c1(int l)
{
    for(int i=0;i<l;i++)
    {
        p[i]=0;
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        n=0;
        cin>>n;
        c(n+2);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>g[i][j];
            }
        }
            //cht.fr.scre 10sc
        for(int i=0;i<n;i++)
        {
            ans+=max(g[i][0],max(g[i][1],g[i][2]));
        }
        cout<<ans;
    }



    return 0;
}
