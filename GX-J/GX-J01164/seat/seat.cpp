#include<bits/c++.h>
using namespce std;
int n,m,a,c,r,c1[105],c2[15][15];
int main()
{
    cin>>n>>>m;
    for(int i = 1;i<=n*m;i++)
    {
        cin>>c1[i];
    }
    a = c1[1];
    for(int i = 1;i<=n*m-1;i++)
    {
        for(int j = 1;j<=n*m-i;j++)
        {
            if(c1[j] >c1[j+1])
            {
                int p = c1[j];
                c1[j] = c1[j+1];
                c1[j+i] = p;
             }
        }
    }
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(i % 2 == 0)
            {
                for(int p = n*i;p>=(i-1)*n+1;p--)
                {
                    c2[i][j] = c1[p];
                }
            }
            else
            {
                for(int q=(i-1)*n+1;q<=i*n+1;q++)
                {
                    c2[i][j] = c1[p];
                }
            }
        }
     }
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(c2[i][j] == a)
            {
                 c = i;
                 r = j;
            }
        }
     }
     cout<<c<<" "<<r;
    return 0;
}
