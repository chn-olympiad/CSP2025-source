#include<bits/stdc++.h>
using namespace std;
int z,w;
string p[3][200005],q[3][200005],s1,s2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>z>>w;
    for(int i=1;i<=z;i++)
    {
        for(int j=1;j<=2;j++)
        {
            cin>>p[j][i];
        }
    }
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=2;j++)
        {
            cin>>q[j][i];
        }
    }
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=z;j++)
        {
            for(int k=0;k<q[1][i].length()-p[1][j].length();k++)
            {
                for(int l=k;l<k+p[1][j].length();l++)
                {
                    s1+=q[1][i][l];
                    s2+=q[2][i][l];
                }
                if(s1==p[1][j]&&s2==p[2][j])
                {
                    z++;
                }
            }
        }
    }
    cout<<z;
    return 0;
}
