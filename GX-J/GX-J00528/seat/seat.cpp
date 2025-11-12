#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    int r;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
        if(i==0)
            r=a[i];
    }
    sort(a,a+(n*m));
    reverse(a,a+(n*m));
    int b[m][n];
    b[0][0]=0;
    for(int i=1;i<n;i++)
        b[0][i]=b[0][i-1]+1;
    for(int i=1;i<m;i++)
    {
        if(i%2!=0)
        {
            for(int j=n-1;j>=0;j--)
            {

                if(j==n-1)
                    b[i][j]=b[i-1][j]+1;
                else
                    b[i][j]=b[i][j+1]+1;
            }
        }
        else
        {
            for(int j=0;j<n;j++)
            {

                if(j==0)
                    b[i][j]=b[i-1][j]+1;
                else
                    b[i][j]=b[i][j-1]+1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[b[i][j]]==r)
            {
                cout<<i+1<<" "<<j+1;
                break;
            }
        }
    }

    return 0;
}
