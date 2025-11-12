#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],s[100][100];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1);
    int l=m*n;
    for(int i=1;i<=n;i++)
    {

        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                s[j][i]=a[l];
                l--;
            }
        }else{

            for(int j=m;j>=1;j--)
            {
                s[j][i]=a[l];
                l--;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {

            if(s[i][j]==x)
            {

                cout<<j<<" "<<i;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
