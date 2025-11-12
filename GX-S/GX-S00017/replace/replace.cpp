#include <iostream>
#include <cmath>
#include <string>
using namespace std;
long long n,q,ans=0;
string hyy[200005][2],myq[200005][2],dif1[200005][2],dif2[200005][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for (int i=0;i<n;i++)
    {
        cin>>myq[i][0]>>myq[i][1];
        for (int j=0;j<myq[i][0].size();j++)
        {
            if (myq[i][0][j]!=myq[i][1][j])
            {
                dif1[i][0]+=myq[i][0][j];
                dif1[i][1]+=myq[i][1][j];
            }
        }
    }
    for (int i=0;i<q;i++)
    {
        ans=0;
        cin>>hyy[i][0]>>hyy[i][1];
        for (int j=0;j<hyy[i][0].size();j++)
        {
            if (hyy[i][0][j]!=hyy[i][1][j])
            {
                dif2[i][0]+=hyy[i][0][j];
                dif2[i][1]+=hyy[i][1][j];
            }
        }
        for (int k=0;k<n;k++)
        {
            if (dif1[k][0]==dif2[i][0] && dif1[k][1]==dif2[i][1])
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
