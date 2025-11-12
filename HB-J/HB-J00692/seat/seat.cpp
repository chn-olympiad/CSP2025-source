#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,i,j,a,p,k=1,z=0,l=0;
    cin>>m>>n;
    int w[m][n],s[m*n],s2[m*n];
    for(i=0;i<m*n;i++)
        cin>>s[i];
    p=s[0];
    for(i=0;i<m*n;i++)
        for(j=0;j<m*n;j++)
            if(s[j]<=s[j+1])
            {
                a=s[j];
                s[j]=s[j+1];
                s[j+1]=a;
            }
    for(i=1;i<=m;i++)
    {
        if(k%2==1)
            for(j=1;j<=n;j++)
            {
                w[i][j]=s[z];
                z++;
            }
        else
            for(j=n;j>=1;j--)
            {
                w[i][j]=s[z];
                z++;
            }
        k++;
    }
    for(j=1;j<=n;j++)
        for(i=1;i<=m;i++)
        {
            s2[l]=w[i][j];
            l++;
        }
    for(i=0;i<m*n;i++)
        if(s2[i]==p)
        {
            freopen("seat.out","w",stdout);
            cout<<i%m+1<<" "<<i/n+1<<endl;
        }
    return 0;
}

