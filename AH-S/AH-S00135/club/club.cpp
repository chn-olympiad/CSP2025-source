#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club1.in","r",stdin);
    freopen("club1.out","w",stdout);
    int t,n,i,j,k,ans,m,w,cut1,q;
    int a[n][3];
    int b[n];
    int p[n];
    int club[3];
    int cuta[2];
    int cut[n];
    cin>>t;
    for (i=0;i<t;i++)
        {
        cin>>n;
        for (j=0;j<n;j++)
            {cin>> a[j][0];
            p[j]=0;b[j]=a[j][0];
            for (k=1;k<3;k++)
           {cin>> a[j][k];
           if(a[j][k]>a[j][k-1])
            {b[j]=a[j][k];
            p[j]=k;}
            club[p[j]]++;}
           }
        for (j=0;j<n;j++)
            ans+=b[j];
        for (j=0;j<3;j++)
            if(club[j]>n/2)
            for (m=0;m<n;m++)
            if(p[m]==j)
        {

            }
        cout<<ans<<endl;
        }
}
