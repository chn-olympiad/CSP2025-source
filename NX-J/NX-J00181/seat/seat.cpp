#include<bits/stdc++.h>
using namespace std;
int n,m,s,z;
bool b[100],c[11][11];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n*m; i++)
    {
        scanf("%d",&s);
        if(i==1)
        {
            z=s;
        }
        b[s]=1;
    }
    int x=100;
    for(int i=1; i<=m; i++)
    {
        if(i%2)
        {
            for(int j=1; j<=n; j++,x--)
            {
                if(b[x]==0)
                {
                    j--;
                    continue;
                }
                if(x==z){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
        else
        {
            for(int j=n; j>=1; j--,x--)
            {
                if(b[x]==0)
                {
                    j--;
                    continue;
                }
                if(x==z){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
