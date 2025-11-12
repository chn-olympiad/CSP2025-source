#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0,l=0,k=1,r=0,c=0,b=0;
    cin>>n>>m;
    vector<int> f;
    int a[m][n];
    for(int i=1;i<=n*m;i++)
    {
        cin>>l;
        f.push_back(l);
    }
    r=f[1];
    sort(f.rbegin(),f.rend());
    for(int i=1;i<=m;i++)
    {
        if(k==1)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=f[b];
                b++;
            }
            k*=-1;
        }
        else
        {
            for(int j=b;j>=1;j--)
            {
                a[i][j]=f[b];
                b++;
            }
            k*=-1;
        }
    }
    k=1;
    for(int i=1;i<=m;i++)
    {
        if(k==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j] == r)
                {
                    cout<<i<<" "<<j<<" ";
                }
                c=j;
            }
            k*=-1;
        }
        else
        {
            for(int j=c;j>=1;j--)
            {
                if(a[i][j] == r)
                {
                    cout<<i<<" "<<j<<" ";
                }
            }
            k*=-1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
